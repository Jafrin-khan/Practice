class Solution {
public:
    
    bool dfs(int node ,int c , vector<int>& color , vector<vector<int>> adj){
        
        for(auto it : adj[node]){
            if(color[it] == -1){
                int adjColor = 1 - c;
                color[it] = adjColor;
                if(!dfs(it , adjColor , color , adj)) return false;
            }
            
            else if(color[it] == c) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        
        int v = adj.size();
//         vector<vector<int>> adj(v);
        
//         for(int i = 0 ; i < v ; i++){
//             for(int j = 0 ; j < graph[i].size() ; j++){
//                 int u = i;
//                 int v = graph[i][j];
                
//                 adj[u].push_back(v);
//                 adj[v].push_back(u);
//             }
//         }
        
        vector<int> color(v , -1);
        
        for(int i = 0 ; i < v ; i++){
            if(color[i] == -1){
                if(!dfs(i , 0 , color , adj)) return false;
            }
        }
        
        return true;
        
    }
};