class Solution {
public:
   /* 
     //Recursion
    //TC = O(2^N)
    //SC = O(N)
    
    int f(int ind , int buy , vector<int>& prices , int n){
        
        if(ind == n) return 0;
        
        int profit = 0;
        
        if(buy){       
            profit = max(-prices[ind] + f(ind+1 , 0 , prices , n) , 0 + f(ind+1 , 1 , prices , n));//max(buy,notBuy);
        }
        else profit = max(prices[ind] + f(ind+1 , 1 , prices , n) , 0 + f(ind+1 , 0 , prices , n));//max(sell,notSell)
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
        return f(0 , 1 , prices , n);
        
    }*/
    
    //Memoised
    //TC = O(N*2)-->O(N)
    //SC = O(N*2) + O(N+2) ~ O(N) + O(N) --> O(N)
    
    int f(int ind , int buy , vector<int>& prices , int n , vector<vector<int>>& dp){
        
        if(ind == n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = 0;
        
        if(buy){       
            profit = max(-prices[ind] + f(ind+1 , 0 , prices , n , dp) , 0 + f(ind+1 , 1 , prices , n , dp));//max(buy,notBuy);
        }
        else profit = max(prices[ind] + f(ind+1 , 1 , prices , n , dp) , 0 + f(ind+1 , 0 , prices , n , dp));//max(sell,notSell)
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2,-1));
        
        return f(0 , 1 , prices , n , dp);
        
    }
};