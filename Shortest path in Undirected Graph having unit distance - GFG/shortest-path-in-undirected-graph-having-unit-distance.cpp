//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   /*
Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). 

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
   
   */
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        
       vector<int> adj[n];
       
       for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
       
       queue<int> q;
       q.push(src);
       
       vector<int> dis(n , 1e9);
       dis[src] = 0;
       
       while(!q.empty()){
           
           int node = q.front();
           q.pop();
           
           for(auto it : adj[node]){
               if(dis[node] + 1 < dis[it]){
                   dis[it] = dis[node] + 1;
                   q.push(it);
               }
           }
       }
       
        for(int i = 0;i<n;i++) {
            if(dis[i] == 1e9) {
                dis[i] = -1; 
            }
        }
       
       return dis;
    }   
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends