class Solution{
public:
    
    /*
    TC = O(V+2E)
    SC = O(3V) ~ O(V)
    */
    
    /*
    This is DFS
    BFS wala bhi h iska prev accepted ans 
    */
    
    bool dfs(int node , vector<vector<int>>& graph , vector<int>& color , int col){
            
        for(auto it : graph[node]){
            
            if(color[it] == -1){
                color[it] = !col;
                if(!dfs(it , graph , color , color[it])){
                    return false;
                }
            }
            
            else{
                if(color[it] == col){
                    return false;
                }
            }
             
        }   
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int m = graph[0].size();
        
        vector<int> color(n , -1);
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(!dfs(i , graph , color , color[i])){
                    return false;
                }
            }
        }
        
        return true;
    }
};