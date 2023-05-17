class Solution {
public:
    
    int f(int ind , int k , vector<int>& nums , vector<vector<int>>& dp){
        if(k == 0) return true;
        if(k < 0) return false;
        if(ind == 0){
            if(nums[ind] == k) return true;
            return false;
        }
        
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int take = f(ind-1 , k - nums[ind] , nums , dp);
        int notTake = f(ind-1 , k , nums , dp);
        
        return dp[ind][k] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(auto it : nums) sum += it;
        
        if(sum%2 != 0) return false;
        sum/=2;
        
        vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
        
        return f(n-1 , sum , nums , dp);
    }
};