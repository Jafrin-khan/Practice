//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//1319. Number of Operations to Make Network Connected...LEETCODE 1319

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
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        
        DisjointSet ds(n);
        int cntExtra = 0;
        
        for(auto it : edges){
            
            int u = it[0];
            int v = it[1];
            
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtra++;
            }
            
            else{
                ds.unionBySize(u,v);
            }
        }
        
        int numComponents = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i] == i){
                numComponents++;
            }
        }
        
        int ans = numComponents-1;
        
        if(ans <= cntExtra){
            return ans;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends