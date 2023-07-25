class Solution {
public:
    
    bool f(int node , int c , vector<vector<int>>& adj , vector<int>& color){
        
        color[node] = c;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(!f(it , 1 - c , adj , color)) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<int> color(n , -1);
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1) if(!f(i , 0 , adj , color)) return false;
        }
        
        return true;
    }
};