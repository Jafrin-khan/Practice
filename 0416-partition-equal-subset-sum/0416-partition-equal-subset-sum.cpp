class Solution {
public:
  
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(auto it : nums) sum += it;
        
        if(sum%2 != 0) return false;
        sum/=2;
        
        vector<vector<int>> dp(n+1 , vector<int>(sum+1 , 0));
        
        for(int ind = 0 ; ind < n ; ind++) dp[ind][0] = true;
        if(nums[0] <= sum) dp[0][nums[0]] = true;
        
        for(int ind = 1 ; ind < n ; ind++){
            for(int k = 1 ; k <= sum ; k++){
                int take = false;
                if(k - nums[ind] >= 0) take = dp[ind-1][k - nums[ind]];
                int notTake = dp[ind-1][k];

                dp[ind][k] = take || notTake;
            }
        }
        
        return dp[n-1][sum];
    }
};