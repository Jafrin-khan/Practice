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
    
 /*    
    //Memoization
    
//    Time Complexity: O(N*M)

// Reason: At max, there will be N*M calls of recursion.

// Space Complexity: O((M-1)+(N-1)) + O(N*M)

// Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.
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
    */
    
    
    //tabulation
    
    //TC = O(N*M)
    //SC = O(N*M)
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , 0));
        
        dp[0][0] = grid[0][0];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
               if(i == 0 && j == 0) continue;
                
               int left = 1e9 , up = 1e9;
                  
               if(j > 0) left = dp[i][j-1];
               if(i > 0)  up = dp[i-1][j];

               dp[i][j] = grid[i][j] + min({left  , up});
            }
        }
        
        return dp[n-1][m-1];
    }
};