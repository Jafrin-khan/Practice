int n = nums.size();
vector<vector<int>> dp(n, vector<int>(n,0));
for(int i = 1 ; i < n ; i++){
dp[i][i] = 0;
}
for(int i = n-1 ; i >= 1 ; i--){
for(int j = i+1 ; j < n ; j++){
int mini = 1e9;
int steps;
int k;
for(k = i ; k < j ; k++){
steps = nums[i-1]*nums[k]*nums[j] + f(i,k,nums , dp) + f(k+1,j,nums , dp);
mini = min(mini , steps);
}
dp[i][j] = mini;
}
}
return dp[1][n-1];