//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(int src, vector<int> adj[] , vector<int>& vis){
         
        queue<pair<int,int>> q; //<node,par>
      
        q.push({src,-1});
        vis[src] = 1;
        
        while(!q.empty()){
            auto front = q.front();q.pop();
            int node = front.first;
            int par = front.second;
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(it != par) return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)) return true;
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