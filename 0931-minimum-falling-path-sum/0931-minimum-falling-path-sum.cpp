class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(i >= m || j < 0 || j >= n){
            return 1e9;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == m-1){
            return grid[i][j];
        }
        
        int left = f(i+1 , j-1 , grid , dp) + grid[i][j];
        int down = f(i+1 , j , grid , dp) + grid[i][j];
        int right = f(i+1 , j+1 , grid , dp) + grid[i][j];
        
        return dp[i][j] = min({left , down , right});
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        
       int n = grid.size();
        int m = grid[0].size();
        int mini = 1e9;
        
        vector<vector<int>> dp(n , vector<int>(m , -1));
    
        for(int i = 0 ; i < m ; i++){
            mini = min(mini , f(0 , i , grid , dp));
        }
        
        return mini;
        
    }
};