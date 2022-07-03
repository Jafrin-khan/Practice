class Solution {
public:
    
    int f(int i , int j , string s1 , string s2 , vector<vector<int>>& dp){
        
        if(i < 0 || j < 0){
            return 0;
        }
          
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);
        }
      
        int x =  f(i - 1 , j , s1 , s2 , dp);
        int y =  f(i , j - 1 , s1 , s2 , dp);
        int z = f(i - 1 , j - 1 , s1 , s2 , dp);
        
        return dp[i][j] = max(x , max(y,z));
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
//          for(int i = 0 ; i <= n  ; i++){
//             dp[i][0] = 0;
//         }
        
//         for(int j = 0 ; j <= m ; j++){
//             dp[0][j] = 0;
//         }
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= m ; j++){
                if(s1[i-1] == s2[j-1]){
                 dp[i][j] = 1 + dp[i-1][j-1];
                 continue;
            }
            
            int x =  dp[i - 1][j];
            int y =  dp[i][j - 1];
            int z =  dp[i - 1][j - 1];

            dp[i][j] = max(x , max(y,z));
            }
        }
        return dp[n][m];
        
    }
};