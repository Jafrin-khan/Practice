class Solution {
public:
    
    int f(int i , int j ,vector<vector<int>>& nums , vector<vector<int>>& dp){
        
        
        if(i == nums.size()-1){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = nums[i+1][j] + f(i+1 , j , nums,dp); 
        int right = nums[i+1][j+1] + f(i+1 , j+1 , nums,dp);
        
        return dp[i][j] = min(right , down);
    }
    int minimumTotal(vector<vector<int>>& nums) {
        
        int n = nums.size();
      
        vector<vector<int>> dp( n , vector<int>(n,-1));
        return f(0 , 0 , nums , dp) + nums[0][0];
        
    }
};