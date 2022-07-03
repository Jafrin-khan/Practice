class Solution {
public:
    

    int longestCommonSubsequence(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));        
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