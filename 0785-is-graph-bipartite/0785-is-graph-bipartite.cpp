class Solution {
public:
    
    //purane submission dekho
    
    bool bfs(int src ,vector<int>& color , vector<vector<int>>& adj){
        
        queue<int> q;
        q.push(src);
        color[src] = 0;
        
        while(!q.empty()){
            
            int node = q.front();q.pop();
            
            for(auto it : adj[node]){
                if(color[it] == -1) {color[it] = 1 - color[node];q.push(it);}
                else if(color[it] == color[node]) return false;
            }
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int n = adj.size();
        
        vector<int> color(n , -1);
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1) if(!bfs(i , color , adj)) return false;
        }
        
        return true;
    }
};