class DisjointSet{
    public:
    
    vector<int> parent;
    vector<int> size;
    DisjointSet(int v){
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

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds(n*m);
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        //STEP1
        //connecting the components
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) continue;
                
                for(int ind = 0 ; ind < 4 ; ind++){
                    int nr = i + dx[ind];
                    int nc = j + dy[ind];
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                        int nodeNo = i*m + j;
                        int adjNodeNo = nr*m + nc;
                        ds.unionBySize(nodeNo , adjNodeNo);
                    }
                }
            }
        }
    
        //STEP2
        //ye chiz hmein hr cell mai krni h jb grid[i][j] = 0 ho
        //jab bhi zero dikhe to adjacent cells jo 1 hai unke ultimate parents ko set mai daalo fir sbki size ko add krke +1 krdo...is ans ko prev ans se check karo aur ans mai max value aayegi , i . e , jiske paas max no. of 1s hai
       int mx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) continue;
                
                set<int> components;
                for(int ind = 0 ; ind < 4 ; ind++){
                    int nr = i + dx[ind];
                    int nc = j + dy[ind];
                     if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                        if(grid[nr][nc] == 1) components.insert(ds.findUPar(nr*m + nc));
                    }
                }
                
                int sizeTotal = 0;
                for(auto it : components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx , sizeTotal + 1);
            }
            

        }
        
        //STEP3
        //agr koi bhi cell 1 ni ye ans chotu hai to hum max size of component considr krenge
        for(int cellNo = 0 ; cellNo < n*n ; cellNo++){
            mx = max(mx , ds.size[ds.findUPar(cellNo)]);
        }
     
        return mx;
    }
    
};