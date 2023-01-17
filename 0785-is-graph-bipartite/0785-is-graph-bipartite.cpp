class Solution {
public:
    
     /*
    TC = O(V+2E)
    SC = O(3V) ~ O(V)
    */
    
    /*
    This is DFS
    BFS wala bhi h iska prev accepted ans 
    */
    
    bool dfs(int node , int col , vector<vector<int>> adj , vector<int>& color){
        
        for(auto it : adj[node]){
            if(color[it] == -1){
                color[it] = 1-col;
                if(!dfs(it , color[it],adj,color)){
                    return false;
                }
            }
            
            else if(color[it] == col){
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int n = adj.size();
        int m = adj[0].size();
        
        vector<int> color(n , -1);
      
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i , 0 , adj , color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};