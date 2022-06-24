class Solution {
public:
    
    int f(int ind , int prev_ind , int len, vector<int>& nums , vector<vector<int>>& dp){
        
        if(ind >= nums.size()){
            return 0;
        }
        
        if(dp[ind][prev_ind+1] != -1){
            return dp[ind][prev_ind+1];
        }
        
        //not taken
        len = 0 + f(ind+1,prev_ind , len , nums , dp);
        
        //taken
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
        len = max(len , 1 + f(ind+1 , ind , len , nums , dp));
        }
        
        return dp[ind][prev_ind+1] = len;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        return f(0 , -1 , 0 , nums , dp);
        
    }
};