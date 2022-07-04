class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,0));
          int p = 0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                   
            if(buy){
                p = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind + 1][1]);
            }

            else{
                p= max(prices[ind] + dp[ind + 1][1] , 0 + dp[ind + 1][0]);
            }

           dp[ind][buy] = p;
            }
        }
        return dp[0][1];
    }
};