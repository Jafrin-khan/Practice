class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m,0));
        
        dp[0][0] = grid[0][0];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                 if(i == 0 && j == 0) continue;
                 
                 int left = 1e9 , up = 1e9;
                
                 if(j >= 1) left = grid[i][j] + dp[i][j-1];
                 if(i >= 1) up = grid[i][j] + dp[i-1][j];
                
                 dp[i][j] = min(left,up);
            }
        }
        return dp[n-1][m-1];
    }
};