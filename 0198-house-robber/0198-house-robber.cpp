class Solution {
public:
    
    int f(int ind , vector<int>& nums , vector<int>& dp){
        
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        
        if(dp[ind] != -1) return dp[ind];
        
        int take = nums[ind] + f(ind-2 , nums , dp);
        int notTake = f(ind-1 , nums , dp);
        
        return dp[ind] = max(take , notTake);
        
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);
        
        vector<int> dp(n , -1);
        
        return f(n-1 , nums , dp);    
    }
};