class Solution {
public:
    /* // Recursion
    
    //TC = 
    //SC = 
    int f(int i , int j , int n , int m , vector<vector<int>>& grid){
        if(i >= n || j >= m || i < 0 || j < 0) return 1e9;
        if(i == 0 && j == 0) return grid[i][j];
        
        int left = f(i , j-1 , n , m , grid);
        int up = f(i-1 , j , n , m , grid);
      
        return grid[i][j] + min({left  , up});
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        return f(n-1 , m-1 , n , m , grid);
    }
    */
    
    //Memoization
    
    //TC = 
    //SC = 
    int f(int i , int j , int n , int m , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i >= n || j >= m || i < 0 || j < 0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == 0 && j == 0) return dp[i][j] =  grid[i][j];
        
        int left = f(i , j-1 , n , m , grid , dp);
        int up = f(i-1 , j , n , m , grid , dp);
      
        return dp[i][j] = grid[i][j] + min({left  , up});
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , -1));
        
        return f(n-1 , m-1 , n , m , grid , dp);
    }
};