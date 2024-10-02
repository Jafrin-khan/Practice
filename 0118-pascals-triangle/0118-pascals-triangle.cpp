class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        ans.push_back({1});
        
        if(n == 1) return ans;
        
        ans.push_back({1,1});
    
        if(n == 2) return ans;
        
        n-=2;
        
        while(n--){
            int m = ans[ans.size()-1].size();
            vector<int> v;
            v.push_back({1});
            for(int i = 1 ; i < m ; i++){
                v.push_back(ans[m-1][i-1] + ans[m-1][i]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        
        return ans;
        
    }
};