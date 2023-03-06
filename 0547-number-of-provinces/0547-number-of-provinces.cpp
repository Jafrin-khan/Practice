class Solution {
public:
    /*
Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over      entire graph, and we know DFS takes a time of O(V+2E). 

Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
    */
    void dfs(int node , vector<int>& vis ,vector<vector<int>> adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , vis , adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        
        int n =  graph.size();
        int m = graph[0].size();
        
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(graph[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) {
                dfs(i , vis , adj);
                ans++;
            }
        }
            
        return ans;
    }
};