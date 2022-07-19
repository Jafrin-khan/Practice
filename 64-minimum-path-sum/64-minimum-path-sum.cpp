class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i >= n || j >= m){
            return 1e9;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        
        int right = grid[i][j] + f(i , j+1 ,grid, dp);
        int down = grid[i][j] + f(i+1 , j ,grid, dp);
        
        return dp[i][j] = min(right , down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , -1));
        
        return f(0 , 0 , grid , dp);
        
    }
};