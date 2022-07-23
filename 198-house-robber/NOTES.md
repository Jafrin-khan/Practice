int rob(vector<int>& nums) {
int n = nums.size();
if(n == 1){
return nums[0];
}
if(n == 2){
return max(nums[0],nums[1]);
}
vector<int> dp(nums.size(),-1);
dp[0] = nums[0];
dp[1] = max(nums[0] , nums[1]);
for(int ind = 2 ; ind < nums.size() ; ind++){
int notPick = dp[ind-1] ;
int pick = 0;
if(ind > 1){
pick =nums[ind] + dp[ind-2] ;
}
dp[ind] = max(pick , notPick);
}
return dp[nums.size()-1];
}