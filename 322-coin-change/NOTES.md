int f(vector<int>& coins, int amount,int ind,vector<vector<int>> &dp){
if(ind == 0){
if(amount%coins[ind] == 0){
return amount/coins[ind];
}
else{
return 1e9;
}
}
if(dp[ind][amount] != -1){
return dp[ind][amount];
}
int notTaken = f(coins,amount,ind-1,dp);
int taken = INT_MAX;
if(coins[ind] <= amount){
taken = 1 + f(coins,amount - coins[ind] , ind,dp);
}
return dp[ind][amount] = min(taken,notTaken);
}
int coinChange(vector<int>& coins, int amount) {
int n = coins.size();
vector<vector<int>> dp(n,vector<int>(amount+1,-1));
int ans = f( coins, amount,n-1,dp);
if(ans == 1e9){
return -1;
}
return ans;
}