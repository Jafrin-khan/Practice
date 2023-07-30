//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        priority_queue<pair<int,int>> pq;
        pq.push({src , 0});
        
        vector<int> dis(v , 1e9);
        dis[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().first;
            int cost = pq.top().second;pq.pop();
            
            for(auto it : adj[node]){
                int nextNode = it[0];
                int wt = it[1];
                
                if(dis[nextNode] > cost + wt){
                    dis[nextNode] = cost + wt;
                    pq.push({nextNode , dis[nextNode]});
                }
            }
        }
        
        return dis;
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