class Solution {
public:
    
    /*
    
    TC =  O(m*n)
    
    SC = O(N*M)  
    */

    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0] == 1){
            return 0;
        }
        
        if(m == 1 && n == 1 && grid[0][0] == 1){
            return 0;
        }
        
        vector<vector<int>> dp(m , vector<int>(n , -1));
        
        dp[0][0] = 1;
        
        for(int i = 0 ; i < m ; i++){ 
            for(int j = 0 ; j < n ; j++){
                
                if(i == 0 && j == 0){
                    continue;
                }
                
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                
                int left = 0;
                int up = 0;
                
                if(j >= 1){
                left = dp[i][j-1];
                }
                
                if(i >= 1){
                up = dp[i-1][j];
                }
                
               dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
           
    }
};