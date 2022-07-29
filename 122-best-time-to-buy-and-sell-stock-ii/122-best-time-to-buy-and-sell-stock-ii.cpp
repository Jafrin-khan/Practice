class Solution {
public:

    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 0 || n == 1){
            return 0;
        }
        vector<vector<int>> dp(n+1 , vector<int>(3,0));
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            
            for(int buy = 1 ; buy >= 0 ; buy--){
                
                 int profit = 0;
        
        
                    if(buy){
                        profit =  max(-prices[ind] + dp[ind+1][0] , 0 + dp[ind + 1][1]);
                    }

                    else{
                        profit = max(prices[ind] + dp[ind + 1][1] ,0 + dp[ind + 1][0]);
                    }

                    dp[ind][buy] = profit;
                
            }
        }
        
        return dp[0][1];
        
    }
};