//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    bool dfs(int node , vector<int>& vis , vector<int>& pathVis , vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it , vis , pathVis , adj)) return true;
            }
            else if(vis[it] && pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int n , vector<int> adj[]) {
        
        vector<int> vis(n , 0);
        vector<int> pathVis(n , 0);
        
        for(int i = 0  ; i < n ; i++){
            if(!vis[i]){
                if(dfs(i , vis , pathVis , adj))return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends