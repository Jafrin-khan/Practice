//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    /*
    Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.
    */
    
    bool check(int node , int par , vector<int>& vis , vector<int> adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(check(it , node , vis , adj)) return true;
            }
            else{
                if(par != it) return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        
        vector<int> vis(v , 0);
        
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                if(check(i , -1 , vis , adj)) return true;
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