//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool f(int node , int col ,  vector<int>& color , vector<int>adj[]){
        
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(!f(it , 1 - col , color , adj)) return false;
            }
            else if(color[it] == col) return false;
        }
        
        return true;
    }
    
	bool isBipartite(int v, vector<int>adj[]){
	    
	    vector<int> color(v , -1);
	    for(int i = 0 ; i < v ; i++){
	        if(color[i] == -1) {if(!f(i , 0 , color , adj)) return false;}
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends