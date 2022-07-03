class Solution {
public:
    
    int f(int ind, vector<int>& coins , int amount , vector<vector<int>>& dp){
      if(amount == 0){
            return 0;
        }
        
    if(dp[ind][amount] != -1){
        return dp[ind][amount];
    }
      if(ind == 0){
          
          if(amount % coins[ind] == 0){
              return amount/coins[ind];
          }
          return 1e9;
      }   
          int notPick = 0 + f(ind-1 , coins , amount , dp);
          int pick = 1e9;
          if(amount >= coins[ind]){
          pick = 1 + f(ind , coins , amount - coins[ind] , dp);
          }
          return dp[ind][amount] = min(pick,notPick);
      }
      
    
    int coinChange(vector<int>& coins, int amount) {
             
             vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
             int ans= f(coins.size()-1 , coins , amount , dp);
             if(ans == 1e9){
                 return -1;
             }
        
             return ans;
    }
};