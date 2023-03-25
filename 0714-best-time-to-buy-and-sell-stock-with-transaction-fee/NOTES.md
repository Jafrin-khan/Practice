int f(int ind , int buy , vector<int>& prices, int fee , int n , vector<vector<int>>& dp){
if(ind == n) return 0;
if(dp[ind][buy] != -1) return dp[ind][buy];
int profit = 0;
if(buy)  profit = max(-prices[ind] + f(ind+1 , 0 , prices , fee , n , dp) , 0 + f(ind+1 , 1 , prices , fee , n , dp));
else profit = max(prices[ind] + f(ind+1 , 1 , prices , fee , n , dp)-fee, 0 + f(ind+1 , 0  , prices , fee , n , dp)); //jab sell krenge tab transaction complete hogi
return dp[ind][buy] = profit;
}