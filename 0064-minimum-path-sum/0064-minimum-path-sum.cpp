class Solution {
public:
    
    /*TC : O(m*n)
    SC : O(N*M)
    */
  
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n , 0));
        
        dp[0][0] = grid[0][0];
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(i == 0 && j == 0){
                    continue;
                }
                int left = 1e9;
                int up = 1e9;
                
                if(j >= 1){
                left = grid[i][j] + dp[i][j-1];
                }
                
                if(i >= 1){
                up = grid[i][j] + dp[i-1][j];
                }
                dp[i][j] = min(left , up);
            }
        }

        
        return dp[m-1][n-1];
        
    }
};