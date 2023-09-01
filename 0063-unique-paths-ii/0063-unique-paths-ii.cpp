class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& dp , vector<vector<int>>& grid){
        
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0 || grid[i][j] == 1) return 0; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = f(i-1 , j , dp , grid);
        int left = f(i , j-1 , dp , grid);
        
        return dp[i][j] = left + up;
    }
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return f(m-1 , n-1 , dp , grid);
    }
};