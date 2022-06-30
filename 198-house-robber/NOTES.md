int helper(vector<int> nums,vector<int> &dp){
int n = nums.size();
if(n == 1){
return nums[0];
}
if(n == 2){
return max(nums[0],nums[1]);
}
dp[0] = nums[0];
dp[1] = max(nums[0],nums[1]);
for(int idx = 2; idx < nums.size() ; idx++){
int notPick = dp[idx-2]+nums[idx];
int pick = dp[idx-1];
dp[idx] =  max(pick,notPick);
}
return dp[nums.size()-1];
}
int rob(vector<int>& nums) {
vector<int> dp(nums.size(),-1);
return helper(nums,dp);
}