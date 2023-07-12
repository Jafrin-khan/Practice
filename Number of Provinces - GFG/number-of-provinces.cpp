//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void bfs(int src , vector<int>& vis , vector<vector<int>>& adj){
        
        vis[src] = 1;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            
            int node = q.front();q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
    }
    int numProvinces(vector<vector<int>> graph, int v) {
        
        vector<vector<int>> adj(v);
        
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < v ; j++){
                if(graph[i][j] == 1){
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        
        int cnt = 0;
        vector<int> vis(v , 0);
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                bfs(i ,vis ,  adj);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends