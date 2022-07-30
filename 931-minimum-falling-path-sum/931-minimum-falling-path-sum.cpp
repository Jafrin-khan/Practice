class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& grid ,  vector<vector<int>>& dp){
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i >= n || j >= m || j < 0){
            return 1e9;
        }
        
         
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == n-1){
            return grid[i][j];
        }
       
        
        int leftD = grid[i][j] + f(i+1 , j-1 , grid , dp);
        int d = grid[i][j] + f(i+1 , j , grid , dp);
        int rightD = grid[i][j] + f(i+1 , j+1 , grid , dp);
        
        return dp[i][j] = min({leftD , d , rightD});
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int mini = 1e9;
        
        vector<vector<int>> dp(n , vector<int>(m,-1));
        
        for(int i = 0 ; i < m ; i++){
            mini = min(mini , f(0 , i , grid , dp));
        }
        
        return mini;
        
    }
};