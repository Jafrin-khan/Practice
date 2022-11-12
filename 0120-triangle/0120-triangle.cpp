class Solution {
public:
       
    int f(int i , int j , vector<vector<int>>& nums , vector<vector<int>>& dp){
        
        int m = nums.size();
        int n = nums[0].size();
      
        if(i == m-1){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int left = nums[i+1][j] + f(i+1 , j , nums , dp);
        int right = nums[i+1][j+1] + f(i+1 , j+1 , nums , dp);
        
        return dp[i][j] = min(left , right);   
        
    }
    
    int minimumTotal(vector<vector<int>>& nums){
        
        int n = nums.size();
        
        vector<vector<int>> dp(n , vector<int>(n,-1));
        return f(0 , 0 , nums , dp) + nums[0][0];
    }
    
};



