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
             
             vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
             int n = coins.size();
            
             for(int i = 0 ; i <= amount ; i++){
                  if(i % coins[0] == 0){
                  dp[0][i] = i/coins[0];
              }
            else{
                     dp[0][i] = 1e9;
                 }
             }
            
             for(int ind = 1 ; ind < n ; ind++){
                 for(int i = 0 ; i <= amount ; i++){
                      int notPick = 0 + dp[ind-1][i];
                      int pick = 1e9;
                      if(i >= coins[ind]){
                      pick = 1 + dp[ind][i - coins[ind]];
                      }
                      dp[ind][i] = min(pick,notPick);
                 }
             }
        
             int ans= dp[coins.size()-1][amount];
             if(ans == 1e9){
                 return -1;
             }
        
             return ans;
    }
};