class Solution {
public:
    /*
   // Recursion
    
     int f(int ind , int buy , vector<int>& prices , int n){
        
        if(ind >= n) return 0;
        
        int profit = 0;
        
        if(buy){       
            profit = max(-prices[ind] + f(ind+1 , 0 , prices , n) , 0 + f(ind+1 , 1 , prices , n));
        }
        else profit = max(prices[ind] + f(ind+2 , 1 , prices , n) , 0 + f(ind+1 , 0 , prices , n));//just this minor change of ind+2 from normal buy and sell stock problem
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
        return f(0 , 1 , prices , n);
        
    }
    */
    
     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2 , vector<int>(2,0));
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy)  profit = max(-prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]);//max(buy,notBuy);
                else profit = max(prices[ind] + dp[ind+2][1] , 0 + dp[ind+1][0]);//max(sell,notSell)
                dp[ind][buy] = profit;
            }
        }
        
        return dp[0][1];
     }
    
};