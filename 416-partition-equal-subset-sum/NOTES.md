​
bool canPartition(vector<int>& nums) {
int sum = 0;
for(auto x : nums){
sum += x;
}
if(sum%2!=0){
return false;
}
int n = nums.size();
vector<vector<int>> dp(n , vector<int>((sum/2)+1 , 0));
for(int i = 0 ; i < n ; i++){
dp[i][0] = 1;
}
if(nums[0] <= (sum/2)){
dp[0][nums[0]] = 1;
}
for(int ind = 1 ; ind < n ; ind++){
for(int k = 1 ; k <= (sum/2) ; k++){
bool notPick = dp[ind-1][k];
bool pick = false;
if(nums[ind] <= k){
pick = dp[ind-1][k - nums[ind]];
}
​
dp[ind][k] = (pick || notPick);
}
}
return dp[n-1][sum/2];
} bool f(int ind , vector<int> nums,  int k , vector<vector<int>> &dp){
if(k == 0){
return true;
}