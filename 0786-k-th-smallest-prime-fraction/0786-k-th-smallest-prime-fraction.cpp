class Solution {
public:
    /*
    1/5 = 0.2
    1/3 = 0.33
    1/2 = 0.5
    2/3 = 0.67
    2/5 = 0.4
    3/5 = 0.6
    
    
    */
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pair<double,pair<int,int>>> pq; //<fraction,n1,n2>
        
        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = i+1 ; j < arr.size() ; j++){
                double fraction = (double)arr[i]/arr[j];
                pq.push({fraction,{arr[i],arr[j]}});
                if(pq.size() > k) pq.pop();
            }
            
        }
        
        auto top = pq.top();pq.pop();
        vector<int> ans;
        
        int n1 = top.second.first;
        int n2 = top.second.second;
        
        ans.push_back(n1);
        ans.push_back(n2);
        
        return ans; 
    }
};