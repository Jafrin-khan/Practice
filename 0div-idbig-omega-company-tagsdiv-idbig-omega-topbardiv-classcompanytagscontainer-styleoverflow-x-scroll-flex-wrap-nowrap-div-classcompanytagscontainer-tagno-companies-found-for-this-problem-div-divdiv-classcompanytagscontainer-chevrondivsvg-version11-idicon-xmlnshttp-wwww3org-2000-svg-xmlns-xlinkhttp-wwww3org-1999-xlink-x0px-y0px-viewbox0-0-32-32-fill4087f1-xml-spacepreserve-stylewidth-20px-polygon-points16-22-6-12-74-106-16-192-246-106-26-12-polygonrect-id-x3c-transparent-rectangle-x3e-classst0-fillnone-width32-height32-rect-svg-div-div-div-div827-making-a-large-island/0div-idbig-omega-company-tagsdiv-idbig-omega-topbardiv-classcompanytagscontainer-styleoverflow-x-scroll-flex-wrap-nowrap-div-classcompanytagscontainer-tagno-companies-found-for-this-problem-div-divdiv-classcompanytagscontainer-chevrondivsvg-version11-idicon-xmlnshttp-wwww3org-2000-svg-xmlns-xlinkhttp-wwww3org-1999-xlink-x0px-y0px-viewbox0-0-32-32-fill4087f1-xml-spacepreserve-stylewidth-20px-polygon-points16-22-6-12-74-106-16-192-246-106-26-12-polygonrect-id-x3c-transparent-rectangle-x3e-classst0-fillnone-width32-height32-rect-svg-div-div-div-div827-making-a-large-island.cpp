class Solution {
public:
    
    class disjointSet{
      
    public:
    
    vector<int> parent;
    vector<int> size;
    disjointSet(int v){
        parent.resize(v+1);
        size.resize(v+1,1);
        for(int i = 0 ; i <= v ; i++) parent[i] = i;
    }
    
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] <= size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    };
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        disjointSet ds(n*n);
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1){
                   
                    for(int i = 0 ; i < 4 ; i++){
                        int nx = row + dx[i];
                        int ny = col + dy[i];
                        
                        if(nx < n && ny < n && nx >= 0 && ny >= 0 && grid[nx][ny] == 1){
                             int cellNum = row*n + col;
                            int adjCellNum = nx*n + ny;
                            ds.unionBySize(cellNum , adjCellNum);
                        }
                    }
                }    
            }
        }
        
        int ans = 0;
        
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 0){
                    
                    set<int> compoParents;
                    for(int i = 0 ; i < 4 ; i++){
                        int nx = row + dx[i];
                        int ny = col + dy[i];
                        
                        if(nx < n && ny < n && nx >= 0 && ny >= 0 && grid[nx][ny] == 1){
                            int adjCellNum = nx*n + ny;
                            compoParents.insert(ds.findUPar(nx*n + ny));
                        }
                    }
                    
                    int connectedIslands = 0;
                    for(auto it : compoParents){
                        connectedIslands += ds.size[it];
                    }
                    
                    ans = max(ans , connectedIslands + 1);
                }
                }
            }
        
        for(int cellNo = 0 ; cellNo < n*n ; cellNo++){
            ans = max(ans , ds.size[ds.findUPar(cellNo)]);
        }
        
        return ans;
    }
};