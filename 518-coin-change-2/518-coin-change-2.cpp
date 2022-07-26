class Solution {
public:
    
    int f(int ind , int amt ,  vector<int>& coins , vector<vector<int>>& dp){
        
    
        if(ind == 0){
            if(amt%coins[ind] == 0){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[ind][amt] != -1){
            return dp[ind][amt];
        }
        
        int notTake = f(ind -1 , amt , coins , dp);
        int take = 0;
        if(amt >= coins[ind]){
            take = f(ind , amt - coins[ind] , coins , dp);
        }
        
        return dp[ind][amt] = take + notTake;
    }
    int change(int amt, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amt + 1 , -1));
        
        return f(n-1 , amt , coins , dp);
    }
};