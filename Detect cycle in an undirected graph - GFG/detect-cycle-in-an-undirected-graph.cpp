//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
     //TC = O(V+2E)
    //SC = O(V)
    
    bool isCycle(int node , vector<int>& vis , vector<int> adj[]){
        queue<pair<int,int>> q;//<node,parent>
        q.push({node,-1});
        vis[node] = 1;
        
        while(!q.empty()){
            int node = q.front().first; 
            int par = q.front().second; q.pop();
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
   
    bool isCycle(int n, vector<int> adj[]) {
        
        vector<int> vis(n,0);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(isCycle(i , vis , adj)) return true;
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