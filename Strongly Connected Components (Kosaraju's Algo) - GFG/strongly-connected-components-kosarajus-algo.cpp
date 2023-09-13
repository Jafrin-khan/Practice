//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
	public:
	
	void dfsStore(int node , stack<int>& st , vector<int>& vis , vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]) dfsStore(it , st , vis , adj);
	    }
	    st.push(node);
	}
	                                                                                    
	void dfs(int node , vector<int>& vis , vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]) dfs(it , vis , adj);
	    }
	}
	                            
    int kosaraju(int v, vector<vector<int>>& adj)
    {   
        stack<int> st;
        vector<int> vis(v,0);
        
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]) dfsStore(i , st , vis , adj);
        }
        
        vector<vector<int>> adjRev(v);
        
        for(int i = 0 ; i < v ; i++){
            vis[i] = 0;
            for(int j = 0 ; j < adj[i].size() ; j++){
                int u = i;
                int v = adj[i][j];
                
                adjRev[v].push_back(u);
            }
        }
        
        int cnt = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                dfs(node , vis , adjRev);
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