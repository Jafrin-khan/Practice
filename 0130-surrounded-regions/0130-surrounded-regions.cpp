class Solution {
public:
    
    void dfs(int i , int j , vector<vector<char>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'X' || grid[i][j] == '$') return;
        
        grid[i][j] = '$';
        
        dfs(i+1 , j , grid);
        dfs(i , j+1 , grid);
        dfs(i-1 , j , grid);
        dfs(i , j-1 , grid);
        
    }
    void solve(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 'O') dfs(i , 0 , grid);
            if(grid[i][m-1] == 'O') dfs(i , m-1 , grid);
        }
        
        for(int j = 0 ; j < m ; j++){
            if(grid[0][j] == 'O') dfs(0 , j , grid);
            if(grid[n-1][j] == 'O') dfs(n-1 , j , grid);
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                if(grid[i][j] == '$') grid[i][j] = 'O';
            }
        }
        
    }
};