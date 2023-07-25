//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool f(int node , vector<int> adj[] , vector<int>& vis , vector<int>& pathVis){
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) {if(f(it , adj , vis , pathVis)) return true;}
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        
        vector<int> vis(v , 0);
        vector<int> pathVis(v , 0);
        
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]) {if(f(i , adj , vis , pathVis)) return true;}
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