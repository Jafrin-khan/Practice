class Solution {
public:
    /*
     //Recursive
    int f(int n){ 
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        int one = f(n-1);
        int two = f(n-2);
        return one + two;
    }
    
    int climbStairs(int n) {
        return f(n);
    }*/
    
    //Memoised
    int f(int n , vector<int>& dp){
        
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int one = f(n-1 , dp);
        int two = f(n-2 , dp);
        return dp[n] = one + two;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return f(n , dp);
    }
    
    //Tabulated
   
   /* int climbStairs(int n) {
        vector<int> dp(n+1 , 0);
        dp[0] = 1;
        dp[1] = 1;
      
        for(int i = 2 ; i <= n ; i++){
            int one = dp[i-1];
            int two = dp[i-2];
        
            dp[i] = one + two;
        }
        
        return dp[n];
    }*/
};