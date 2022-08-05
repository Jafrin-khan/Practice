class Solution {
public:
    
        void dfs(int src, vector<bool>& vis, vector<vector<int>>& adj)
    {
        vis[src] = true;
        for(auto it: adj[src])
        {
            if(!vis[it])
              dfs(it, vis, adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
          if(connections.size() < n-1)
        {
            return -1;
        }
        
        vector<vector<int>> adj(n);
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        int components = 0; 
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(i, vis, adj);
            }
        }
        return components - 1;
        
    }
};