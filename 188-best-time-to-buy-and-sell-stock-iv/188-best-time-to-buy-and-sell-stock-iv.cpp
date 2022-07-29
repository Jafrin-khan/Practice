class Solution {
public:
    
     int f(int ind , int buy , int trans , vector<int>& prices ,  vector<vector<vector<int>>>& dp){
        
        int n = prices.size();
        
        if(ind == n){
            return 0;
        }
        
        if(trans == 0){
            return 0;
        }
        
        if(dp[ind][buy][trans] != -1){
            return dp[ind][buy][trans];
        }
        
        int profit = 0;
        
        
        if(buy){
            profit =  max(-prices[ind] + f(ind+1 , 0 , trans ,prices , dp) , 0 + f(ind + 1 , 1 ,trans , prices , dp));
        }
        
        else{
            profit = max(prices[ind] + f(ind + 1 , 1 ,trans-1 , prices , dp) ,0 + f(ind + 1 , 0 ,trans , prices , dp) );
        }
        
        return dp[ind][buy][trans] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1,-1)));
        return f(0 , 1 , k , prices , dp);
        
    }
};