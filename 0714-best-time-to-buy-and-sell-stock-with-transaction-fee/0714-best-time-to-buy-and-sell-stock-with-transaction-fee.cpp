class Solution {
public:
   /* 
    //Recursion
    //TC = O(2^N)
    //SC = O(N)
    
    int f(int ind , int buy , vector<int>& prices, int fee , int n){
        
        if(ind == n) return 0;
        
        int profit = 0;
        
        if(buy)  profit = max(-prices[ind] + f(ind+1 , 0 , prices , fee , n) , 0 + f(ind+1 , 1 , prices , fee , n));
        else profit = max(prices[ind] + f(ind+1 , 1 , prices , fee , n)-fee, 0 + f(ind+1 , 0  , prices , fee , n)); //jab sell krenge tab transaction complete hogi
        return profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        return f(0 , 1 , prices , fee , n);
        
    }*/
    
     //Memoised
    //TC = O(N*2)
    //SC = O(N*2) + O(N+2)
    
    int f(int ind , int buy , vector<int>& prices, int fee , int n , vector<vector<int>>& dp){
        
        if(ind == n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = 0;
        
        if(buy)  profit = max(-prices[ind] + f(ind+1 , 0 , prices , fee , n , dp) , 0 + f(ind+1 , 1 , prices , fee , n , dp));
        else profit = max(prices[ind] + f(ind+1 , 1 , prices , fee , n , dp)-fee, 0 + f(ind+1 , 0  , prices , fee , n , dp)); //jab sell krenge tab transaction complete hogi
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2,-1));
        return f(0 , 1 , prices , fee , n , dp);
        
    }
};