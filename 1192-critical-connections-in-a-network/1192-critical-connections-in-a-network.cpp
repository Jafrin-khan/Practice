class Solution {
public:
    //TC = O(V+2E)
    //SC = O(V+2E) + O(3N)
    void dfs(int node , int parent , int timer , vector<int>& vis , vector<int> adj[] , vector<int>& tin , vector<int>& low , vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it , node , timer , vis , adj , tin , low , bridges);
                low[node] = min(low[node] , low[it]);
                if(low[it] > tin[node]) bridges.push_back({node,it});
            }
            
            else low[node] = min(low[node] , low[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> tin(n);
        vector<int> low(n);
        int timer = 1;
        
        vector<int> vis(n , 0);
        
        vector<vector<int>> bridges;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) dfs(i , -1 , timer , vis , adj , tin , low , bridges);
        }
        
        return bridges;
    }
};