int rob(vector<int>& nums) {
// state variable : i -> current house index
// dp[i] = max profit which we can get from firt i houses
int n = nums.size();
int dp[n];
//Base cases
dp[0] = nums[0];
if(n>1){
dp[1] = max(nums[0] , nums[1]);
}
for(int i = 2 ; i < n ; i++ ){
// Recurrence Relation
dp[i] = max(dp[i-1] , dp[i-2] +  nums[i]);
}
return dp[n-1];
}