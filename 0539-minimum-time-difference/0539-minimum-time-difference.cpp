class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
    
    // https://www.youtube.com/watch?v=-QAC8MgJEAI
    
    int findMinDifference(vector<string>& s){
        vector<int> v;
        
        //converting and storing mins
        for(int i = 0 ; i < s.size() ; i++){
            string hrs = s[i].substr(0,2);
            string mins = s[i].substr(3);
            
            int h = stoi(hrs);
            int m = stoi(mins);  
            
            v.push_back(h*60 + m);
        }
        
        sort(v.begin() , v.end());
        
        //diff nikaalre h starting from ind 1
        int ans =  1e9;
        for(int i = 1 ; i < v.size() ; i++){
            ans = min(ans , v[i]-v[i-1]);
        }
        
        //edge case k lie
        ans = min(ans , 24*60-v[v.size()-1] + v[0]);
        
        return ans;
    }
};