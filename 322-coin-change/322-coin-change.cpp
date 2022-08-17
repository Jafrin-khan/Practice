class Solution {
public:
    
    int f(int ind , int amt , vector<int>& coins , vector<vector<int>>& dp){
        
        int n = coins.size();
       
        if(ind == 0){
            if(amt%coins[ind] == 0){
                return amt/coins[ind];
            }
            
            return 1e9;
        }
        
        if(dp[ind][amt] != -1){
            return dp[ind][amt];
        }
        
        int notTaken = 0 + f(ind-1 , amt , coins , dp);
        int taken = 1e9;
        
        if(amt-coins[ind] >= 0){
            taken = 1 + f(ind, amt-coins[ind] , coins , dp);
        }
        
        return dp[ind][amt] = min(taken , notTaken);
    }
        
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        
        int ans = f(n-1 , amount , coins , dp);
        
        if(ans == 1e9){
            return -1;
        }
        
        return ans;
        
        
        
    }
};