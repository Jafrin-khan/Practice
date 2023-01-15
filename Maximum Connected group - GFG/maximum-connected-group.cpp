//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


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
   
   bool isValid(int row , int col , int n , int m){
       return row >= 0 && col >= 0 && row < n && col < m;
   }
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds(n*m);
        
        //step1
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 0)continue;
                int dr[] = {-1 , 0 , +1 , 0};
                int dc[] = {0 , +1 , 0 , -1};
                for(int ind = 0 ; ind < 4 ; ind++){
                    int nr = row + dr[ind];
                    int nc = col + dc[ind];
                    if(isValid(nr , nc , n , m) && grid[nr][nc] == 1){
                        int nodeNo = row*m + col;
                        int adjNodeNo = nr*m + nc;
                        ds.unionBySize(nodeNo , adjNodeNo);
                    }
                }
            }
        }
        
        //steps2
        int mx = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 1)continue;
                int dr[] = {-1 , 0 , +1 , 0};
                int dc[] = {0 , +1 , 0 , -1};
                set<int> components;
                for(int ind = 0 ; ind < 4 ; ind++){
                    int nr = row + dr[ind];
                    int nc = col + dc[ind];
                    if(isValid(nr , nc , n , m)){
                        if(grid[nr][nc] == 1){
                            components.insert(ds.findUPar(nr*n + nc));
                        }
                    }
                }
                
                int sizeTotal = 1;
                for(auto it : components){
                    sizeTotal += ds.size[it];
                }
                
                mx = max(mx , sizeTotal);
            }
        }
        
        //when all are 1s
        for(int cellNo = 0 ; cellNo < n*m ; cellNo++){
            mx = max(mx,ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends