class Solution {
public:
    
    //BILKUL BHI FOLLOW MT KRNA YE WALA CODE ISSE NICHE WAALE COMMNTED DEKHO
    int f(int ind , int k , vector<int>& nums , vector<vector<int>>& dp){
        
        if(ind == 0){
            if(k == 0 && nums[0] == 0) return 2;
            if(k == 0 || k == nums[0]) return 1;
            return 0;
        }
        
        
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int notTake = f(ind - 1 , k , nums , dp);
        int take = 0;
        if(k >= nums[ind]) take = f(ind - 1 , k - nums[ind] , nums , dp);
        
        return dp[ind][k] = take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totSum = 0;
        for(auto it : nums) totSum += it;
        
        int s2 = (totSum - target)/2;
        if((totSum - target) < 0  || (totSum - target)%2 == 1) return 0;
        
        vector<vector<int>> dp(nums.size() , vector<int>(s2 + 1 , -1)); 
        return f(nums.size()-1 , s2 , nums , dp);
    }
};