class Solution {
public:
    
    int f(int ind , int buy , int t , vector<int>& prices, vector<vector<vector<int>>>& dp){
        
        if(t <= 0 || ind >= prices.size()){
            return 0;
        }
        
        if(dp[ind][buy][t] != -1){
            return dp[ind][buy][t];
        }
        
        int p = 0;
        if(buy){
            p = max(-prices[ind] + f(ind+1 , 0 , t , prices , dp) , 0 + f(ind + 1 , 1 , t , prices , dp));
        }
        
        else{
            p = max(prices[ind] + f(ind+1 , 1 , t-1 , prices , dp) , 0 + f(ind + 1 , 0 , t , prices , dp));
        }
        
        return dp[ind][buy][t] = p;
    }
    int maxProfit(vector<int>& prices) {
        
        int n  = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0 , 1 , 2 , prices , dp);
    }
};