class Solution {
public: 
    
    bool isCycle(int v , vector<int>& vis , vector<vector<int>>& adj  , vector<int>& dfsVis){
            vis[v] = 1;
            dfsVis[v] = 1;
            for(auto it : adj[v]){
                if(!vis[it]){
                    if(isCycle(it , vis , adj ,  dfsVis)) return true;
                }
                
                else{
                    if(dfsVis[it] == 1) return true;
                }
            }
        
        dfsVis[v] = 0;
        
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n);
        
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[v].push_back(u);//pehle v fulfilled hona chahie tb jaake u course kr skte
        }
        
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(isCycle(i,  vis , adj , dfsVis)) return false;
            } 
        }
        return true;
    }
};