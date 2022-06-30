class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& nums , vector<vector<int>>& dp){
        
        int m = nums.size();
        int n = nums[0].size();
        
        if(i >= m || j >= n){
            return 0;
        }
        
        if(i <= m-1 && j <= n-1 && nums[i][j] == 1){
            return 0;
        }
        
        if(i == m-1 && j == n-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = f(i+1,j , nums , dp);
        int right = f(i , j+1 , nums , dp);
        
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        
        int m = nums.size();
        int n = nums[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(0 ,0 ,nums,dp);
    }
};