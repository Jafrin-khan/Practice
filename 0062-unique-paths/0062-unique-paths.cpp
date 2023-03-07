class Solution {
public:
  /*
Memoization
Time Complexity: O(M*N)

Reason: At max, there will be M*N calls of recursion.

Space Complexity: O((N-1)+(M-1)) + O(M*N)

Reason: We are using a recursion stack space:O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.
    */

    int f(int i , int j , vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = f(i-1,j,dp);
        int up = f(i,j-1,dp);
        
        return dp[i][j] = left + up;
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(m-1 , n-1,dp);
    }
};