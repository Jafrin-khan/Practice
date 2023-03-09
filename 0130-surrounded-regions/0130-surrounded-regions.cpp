class Solution {
public:
    /*
    TC = O(M*N).....every element of matrix is processed at most three times.
    
    SC = O(M*N)...Stack space in recursive call
    */
    void dfs(int i , int j , int n , int m , vector<vector<char>>& grid ,  vector<vector<int>>& vis){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O') return;
        
        vis[i][j] = 1;
        grid[i][j] = '$';
        
        dfs(i+1,j,n,m,grid,vis);
        dfs(i,j+1,n,m,grid,vis);
        dfs(i-1,j,n,m,grid,vis);
        dfs(i,j-1,n,m,grid,vis);
    }
    void solve(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 'O' && !vis[i][0]) dfs(i,0,n,m,grid,vis); 
            if(grid[i][m-1] == 'O' && !vis[i][m-1]) dfs(i,m-1,n,m,grid,vis);
        }
        
        for(int j = 0 ; j < m ; j++){
            if(grid[0][j] == 'O' && !vis[0][j]) dfs(0,j,n,m,grid,vis);
            if(grid[n-1][j] == 'O' && !vis[n-1][j]) dfs(n-1,j,n,m,grid,vis);
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '$') grid[i][j] = 'O';
                else grid[i][j] = 'X';
            }
        }
        
    }
};