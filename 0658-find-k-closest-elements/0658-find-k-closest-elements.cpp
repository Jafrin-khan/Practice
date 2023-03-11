class Solution {
public:
    /*
    TC = O(N) + O(K) + O(KlogK)
    SC = O(K)
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        
        priority_queue<pair<int,int>> pq; //<diff,element>
        
        for(int i = 0 ; i < n ; i++){
            if(pq.size() < k) pq.push({abs(x-arr[i]) , arr[i]});
            else if(pq.top().first > abs(x-arr[i])){
                pq.pop();
                pq.push({abs(x-arr[i]) , arr[i]});
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};