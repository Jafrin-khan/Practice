class Solution {
public:
    
    //purane submission dekho
    
//     bool bfs(int src ,vector<int>& color , vector<vector<int>>& adj){
        
//         queue<int> q;
//         q.push(src);
//         color[src] = 0;/////////COLOR[SRC] TO DEFINE KRO WO HI NAHI KARA THA AUR SUBMIT KRNE CHALE
        
//         while(!q.empty()){
            
//             int node = q.front();q.pop();
            
//             for(auto it : adj[node]){
//                 if(color[it] == -1) {color[it] = 1 - color[node];q.push(it);}////////////PUSH KRNA NAHI BHULNA
//                 else if(color[it] == color[node]) return false;
//             }
            
//         }
        
//         return true;
//     }
    
    bool dfs(int src , int col , vector<int>& color , vector<vector<int>>& adj){
         
        for(auto it : adj[src]){
            if(color[it] == -1){
                color[it] = !col;
                if(!dfs(it , !col , color , adj)) return false;
            }
            else if(color[it] == col) return false;
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int n = adj.size();
        
        vector<int> color(n , -1);
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i , 0 , color , adj)) return false;
            }
        }
        
        return true;
    }
};