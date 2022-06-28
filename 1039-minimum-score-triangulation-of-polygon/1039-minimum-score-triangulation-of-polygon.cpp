class Solution {
public:
    
    int f(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
        
        if(i == j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mini = 1e9;
        int steps;
        int k;
        for(k = i ; k < j ; k++){
            steps = nums[i-1]*nums[k]*nums[j] + f(i,k,nums , dp) + f(k+1,j,nums , dp);
            mini = min(mini , steps);
        }
        
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(1 , n-1 , nums , dp);
        
    }
};