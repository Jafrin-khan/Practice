//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfsStore(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfsStore(it, adj, st, vis);
        }
    }
    st.push(node);
}

void dfs(int node, vector<vector<int>>& adjRev, vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adjRev[node]) {
        if (!vis[it]) {
            dfs(it, adjRev, vis);
        }
    }
}

int kosaraju(int v, vector<vector<int>>& adj) {
    stack<int> st;
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfsStore(i, adj, st, vis);
        }
    }

    vector<vector<int>> adjRev(v);
    for (int i = 0; i < v; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjRev[it].push_back(i);
        }
    }

    int cnt = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            cnt++;
            dfs(node, adjRev, vis);
        }
    }

    return cnt;
}
  
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends