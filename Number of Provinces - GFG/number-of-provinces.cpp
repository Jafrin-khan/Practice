//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

  //Method using disjoint set
  
class DisjointSet{

    public:
    vector<int> size , parent;
    DisjointSet(int n){
        size.resize(n+1 , 1);
        parent.resize(n+1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
    
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
  
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        DisjointSet ds(v);
        
        for(int i = 0 ; i < adj.size() ; i++){
            for(int j = 0 ; j < adj[0].size() ; j++){
                if(adj[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < v ; i++){
            if(ds.parent[i] == i){
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