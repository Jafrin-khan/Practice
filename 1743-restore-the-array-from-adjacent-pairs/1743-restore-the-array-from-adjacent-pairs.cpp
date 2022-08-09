class Solution {
public:
    
    void dfs(int node , set<int>& vis ,vector<int>& ans , unordered_map<int , vector<int>>& adj){
        
        ans.push_back(node);
          vis.insert(node);
        for(auto it : adj[node]){
            if(!vis.count(it)){
              
                dfs(it , vis , ans , adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& nums) {
        
        unordered_map<int , vector<int>> adj;
       
        
        for(auto x : nums){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        int f;
        int n = adj.size();
        
        for(auto it : adj){
            
            if(it.second.size() == 1){
                f = it.first;
                break;
            }
        }
        
        vector<int> ans;
        set<int> vis;
        
        ans.push_back(f);
        vis.insert(f);
        
        for(auto it : adj[f]){
            
            if(!vis.count(it)){
            dfs(it , vis , ans , adj);
            }
        }
        
        return ans;
        
        
    }
};