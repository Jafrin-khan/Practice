class Solution {
public:
    

    int minScoreTriangulation(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
    
    for(int i = n-1 ; i >= 1 ; i--){
            
        for(int j = i+1 ; j < n ; j++){
            
            int mini = 1e9;
            int steps;
            int k;
            for(k = i ; k < j ; k++){
                steps = nums[i-1]*nums[k]*nums[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini , steps);
        }
        
        dp[i][j] = mini;
           
           
        }
    }
        return dp[1][n-1];
        
    }
};