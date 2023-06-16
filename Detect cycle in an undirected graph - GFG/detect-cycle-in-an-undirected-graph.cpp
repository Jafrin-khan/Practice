//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(int src ,int par, vector<int> adj[] , vector<int>& vis){
        queue<pair<int,int>> q;
        q.push({src,par});
        vis[src] = 1;
        
        while(!q.empty()){
            auto front = q.front(); q.pop();
            int node = front.first;
            int par = front.second;
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it , node});
                    vis[it] = 1;
                }
                else if(par != it) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        
        vector<int> vis(v , 0);
        
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                if(bfs(i , -1 , adj , vis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends