class Solution {
public:
    
    
    int helper(int n , vector<int> &dp){
         int n1, n2, sum = 0;
 
    // Base cases
    if (n == 1 || n == 0)
        return 1;
 
    if(dp[n] != -1){
        return dp[n];
    }
    // Find the nth Catalan number
    for (int i = 1; i <= n; i++) {
 
        // Recursive calls
        n1 = helper(i - 1,dp);
        n2 = helper(n - i,dp);
        sum += n1 * n2;
    }
 
    // Return the nth Catalan number
    return dp[n] =  sum;

    }
    int numTrees(int n) {
           
       vector<int> dp(n+1,-1);
        return helper(n,dp);
        
    }
};