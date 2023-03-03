class Solution {
public:
    //recursive
    /*
    TC = Exponential,,,,,mp --> O(2^N) {check from friend}
    SC = O(N)
    
    int f(int n){
        if(n == 1) return 1;
        if(n == 0) return 1;
        
        int one = f(n-1);
        int two = f(n-2);
        return one+two;
    }
    
    int climbStairs(int n) {
        return f(n);
    }
    */
    
    //memoised
    /*
    dono check karo TC and SC
    TC = O(N)
    SC = O(N)
    */
    
    int f(int n , vector<int>& dp){
        if(n == 1) return 1;
        if(n == 0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int one = f(n-1 , dp);
        int two = f(n-2 , dp);
        return dp[n] = one+two;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return f(n,dp);
    }
    
};