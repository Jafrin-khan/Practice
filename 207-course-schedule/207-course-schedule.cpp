class Solution {
public:
    
    bool isCycle(int node , int prev , vector<int>& vis , vector<int> adj[] , vector<int>& dfsVis){
        
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it : adj[node]){
            
            if(!vis[it] && isCycle(it , node , vis , adj , dfsVis)){
                return true;
            }
            
            else if(dfsVis[it] == 1){
                return true;
            }
        }
        
        dfsVis[node] = 0;
        
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& nums) {
        
        vector<int> adj[v];
        vector<int> dfsVis(v , 0);
        vector<int> vis(v,0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            int u = nums[i][0];
            int v = nums[i][1];
            
            adj[u].push_back(v);
        }
        
        for(int i = 0 ; i < v ; i++){
            
            if(!vis[i] && isCycle(i ,-1, vis , adj , dfsVis)){
               return false;
            }
        }
        
        return true;
        
    }
};