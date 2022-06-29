class Solution {
public:

    int climbStairs(int n) {
        
       vector<int> dp(n+2,-1);
       
       dp[0] = 0;
       dp[1] = 1;
       dp[2] = 2;
        
       for(int i = 3 ; i <= n ; i++){
             
        int x = dp[i-1];
        int y = dp[i-2];
        
        dp[i] = x+y;
       }
       
       return dp[n] ;
    }
};