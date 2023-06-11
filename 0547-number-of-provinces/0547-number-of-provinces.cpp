class Solution {
public:
    
    //see first solution for referring code
    void dfs(int node , vector<int>& vis , vector<vector<int>> adj){
        vis[node] = 1;//////////////////////////////
        for(auto it : adj[node]){
            if(!vis[it]){
            dfs(it,vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v = isConnected.size();
        
        vector<vector<int>> adj(v);/////////////////////////////////////   V DAALNA IS IMP //////////////////////////////////////
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < isConnected[0].size() ; j++){
                if(i != j){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }}
        vector<int> vis(v,0);
        int cnt = 0;
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i , vis , adj);
            }
        }
            
        return cnt;
    }
};