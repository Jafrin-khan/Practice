//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> vis(v,0);
        int sum = 0;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;//<wt,node>
        //<WT , NODE> ISSI ORDER MAI HONA CHAHIYE COZ HUM PRIORITY QUEUE WEIGHT KO DEC ORDER MAI SORT KRNE K LIE USE KRRE HAI
        pq.push({0 , 0});
        
        
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(!vis[node]){
                vis[node] = 1;
                sum += wt;
                
                for(auto it : adj[node]){
                    if(!vis[it[0]]){
                    pq.push({it[1],it[0]});
                    }
                }
            }
        }
        
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends