class Solution {
public:
    
    void dfs(int node , vector<int>& vis , vector<vector<int>>& adj){
        
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it , vis , adj);
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(graph[i][j] == 1){
                int u = i;
                int v = j;
                adj[u].push_back(v);
                adj[v].push_back(u);
                }
            }
        }
        
        vector<int> vis(n , 0);
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                ans++;
                dfs(i , vis , adj);
            }
        }
        
        return ans;
    }
};