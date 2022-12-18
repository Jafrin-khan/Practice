//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
     bool dfs(int node , vector<int>& vis , vector<int>& dfsVis , vector<int> adj[] , vector<int>& check){
        
        vis[node] = 1;
        dfsVis[node] = 1;
        check[node] = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
               if(dfs(it , vis , dfsVis , adj , check)){
                   return true;
               }
            }
            
           else if(dfsVis[it] == 1){
                return true;
            }
            }
        
        check[node] = 1;
        dfsVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int v, vector<int> graph[]) {
        // code here
         vector<int> vis(v , 0);
        vector<int> dfsVis(v , 0);
        vector<int> check(v , 0);
        
        for(int i = 0 ; i < v ; i++){
            
            if(!vis[i]){
                dfs(i , vis , dfsVis , graph , check);
            }
        }
        
        vector<int> ans;
        
        for(int i = 0 ; i < check.size() ; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends