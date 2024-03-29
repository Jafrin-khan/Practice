/*

DFS APPROACH

 void dfs(int i, vector<int> &vis, vector<vector<int>>& stones){
        vis[i]=1;
        for(int u=0;u<stones.size();u++){
            if(!vis[u] && (stones[u][1]==stones[i][1] || stones[u][0]==stones[i][0]))
                dfs(u, vis, stones);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int v=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, stones);
                    v++;
            }
        }
        return n-v;
    }

*/

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
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        
        int maxRow = 0;
        int maxCol = 0;
        
        //for finding the grid size
        for(auto it : stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow , nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it : stoneNodes){
            if(ds.findUPar(it.first) == it.first) cnt++;
        }
        
        return n - cnt;
    }
};