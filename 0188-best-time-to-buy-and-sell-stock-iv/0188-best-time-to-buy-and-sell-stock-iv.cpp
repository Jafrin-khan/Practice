class Solution {
public:
    
    /*
    //Recursion
     int f(int ind , int buy , int t , vector<int>& prices , int n , int k){
        
        if(ind == n || t == k) return 0;
        
        int profit = 0;
        
        if(buy){       
            profit = max(-prices[ind] + f(ind+1 , 0 ,t, prices , n , k) , 0 + f(ind+1 , 1 ,t,  prices , n ,k));
        }
        else profit = max(prices[ind] + f(ind+1 , 1 ,t+1, prices , n , k) , 0 + f(ind+1 , 0 ,t,  prices , n ,k));//jab sell krenge tab transaction complete hogi islie sirf yahi t+1
        
        return profit;
    }
  
    int maxProfit(int k, vector<int>& prices) {
         
        int n = prices.size();
        return f(0 , 1 , 0 , prices , n , k);
    }
    */
    
    //memoised
    int f(int ind , int buy , int t , vector<int>& prices , int n , int k , vector<vector<vector<int>>>& dp){
        
        if(ind == n || t == k) return 0;
        
        if(dp[ind][buy][t] != -1){
            return dp[ind][buy][t];
        }
        
        int profit = 0;
        
        if(buy){       
            profit = max(-prices[ind] + f(ind+1 , 0 ,t, prices , n , k , dp) , 0 + f(ind+1 , 1 ,t,  prices , n ,k , dp));
        }
        else profit = max(prices[ind] + f(ind+1 , 1 ,t+1, prices , n , k , dp) , 0 + f(ind+1 , 0 ,t,  prices , n ,k , dp));//jab sell krenge tab transaction complete hogi islie sirf yahi t+1
        
        return dp[ind][buy][t] = profit;
    }
  
    int maxProfit(int k, vector<int>& prices) {
         
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k+1,-1)));
        return f(0 , 1 , 0 , prices , n , k , dp);
    }
};