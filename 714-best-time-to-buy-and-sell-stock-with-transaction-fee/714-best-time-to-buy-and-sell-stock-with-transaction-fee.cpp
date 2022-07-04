class Solution {
public:
    
    int f(int ind , int buy , vector<int>& prices , int n , int profit , vector<vector<int>>& dp ,int fee){
        
        if(ind == n){
            return 0;
        }
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        
        if(buy){
              //take or not_take
              dp[ind][buy] = max(-prices[ind]-fee + f(ind+1,0,prices,n,profit,dp,fee),0 +f(ind+1,1,prices,n,profit,dp,fee ));
        }
                            
        else{
           dp[ind][buy] =  max(prices[ind] + f(ind+1,1,prices,n,profit,dp,fee) , 0 + f(ind+1,0,prices,n,profit,dp,fee));
        }
        
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,prices.size(),0,dp,fee);
        
    }
};