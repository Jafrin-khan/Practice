class Solution {
public:
  /*
   // Memoization
    Time Complexity: O(M*N)

    Reason: At max, there will be M*N calls of recursion.

    Space Complexity: O((N-1)+(M-1)) + O(M*N)

    Reason: We are using a recursion stack space:O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array       of size ‘M*N’.


    int f(int i , int j , vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = f(i-1,j,dp);
        int up = f(i,j-1,dp);
        
        return dp[i][j] = left + up;
    }
 */
 
    /*
    //tabulation
    TC = 
    SC = 
    */
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,0));
        dp[0][0] = 1;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
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