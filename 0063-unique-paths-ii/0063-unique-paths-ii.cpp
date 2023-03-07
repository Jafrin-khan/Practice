class Solution {
public:
    /*
    //memoization
    TC = O(M*N)
    SC = O(M*N)
    
     int f(int i , int j , vector<vector<int>>& dp , vector<vector<int>>& grid){
        if(i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = f(i-1,j,dp,grid);
        int up = f(i,j-1,dp,grid);
        
        return dp[i][j] = left + up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        
        return f(m-1,n-1,dp,grid);
        
    }
    */
    
    /*
    //Tabulation
    
    
    */
     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
         
        if(grid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(m , vector<int>(n,0));
        dp[0][0] = 1;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
               
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                 if(i == 0 && j == 0) continue;
                 int left = 0, up = 0;
                
                 if(i > 0) left = dp[i-1][j];
                 if(j > 0) up = dp[i][j-1];

                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
        
    }
};