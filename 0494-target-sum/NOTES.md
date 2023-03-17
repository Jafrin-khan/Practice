​
for(int target = 0 ; target <= s2 ; target++){
if(target == 0 && nums[0] == 0) dp[0][0] = 2;
else if(target == 0 || target == nums[0]) dp[0][target] = 1;
else dp[0][target] = 1;
}