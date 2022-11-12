int minimumTotal(vector<vector<int>>& nums){
int m = nums.size();
int n = nums[0].size();
vector<vector<int>> dp(m , vector<int>(m,-1));
for(int i = 0 ; i < n ; i++){
dp[m-1][i] = 0;
}
for(int i = (m-2) ; i >= 0 ; i--){
for(int j = i ; j >= 0 ; j--){
int left = nums[i+1][j] + dp[i+1][j];
int right = nums[i+1][j+1] + dp[i+1][j+1];
​
dp[i][j] = min(left , right);
}
}
return dp[0][0] + nums[0][0];
}