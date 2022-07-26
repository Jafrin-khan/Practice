class Solution {
public:
    
    int f(int n , vector<int>& dp){
        
        if(n == 1 || n == 0){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        int sum = 0;
        
        for(int i = 1;i <= n ; i++){
            int n1 = f(i-1 , dp);
            int n2 = f(n-i , dp);
            
            sum += n1*n2;
        }
        
        return dp[n] = sum;
    }
    int numTrees(int n) {
        
        vector<int> dp(n+1, -1);
        return f(n , dp);
    }
};