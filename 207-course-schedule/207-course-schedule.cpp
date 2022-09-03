class Solution {
public:
    
    bool isCycle(int node , vector<int> adj[] , vector<int>& vis , vector<int>& dfsVis){
        
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it : adj[node]){
            
            if(!vis[it]){
                if(isCycle(it , adj , vis , dfsVis)){
                    return true;
                }
            }
            
            else if(dfsVis[it] == 1){
                return true;
            }
        }
        
        dfsVis[node] = 0;
        return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& nums) {
        
        vector<int> adj[n];
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int u = nums[i][0];
            int v = nums[i][1];
            
            adj[u].push_back(v);
            
        }
        
        vector<int> vis(n,0);
        vector<int> dfsVis(n , 0);
        
        for(int i = 0 ; i < n ; i++){
            
            if(!vis[i] && isCycle(i , adj , vis , dfsVis)){
                return false;
            }
        }
        
        return true;
        
    }
};

