//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    /*
Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.

Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
    */
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // Code here
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> dist(v , 1e9);
        
        dist[src] = 0;
        pq.push({0 , src});
        
        while(!pq.empty()){
            
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it : adj[node]){
                int currDis = it[1];
                int currNode = it[0];
                
                if(dist[currNode] > dis + currDis){
                    dist[currNode] = dis + currDis;
                    pq.push({dist[currNode] , currNode});
                }
            }
        }
        
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends