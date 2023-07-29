class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n , 1);
        
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(nums[ind] > nums[prev] && dp[ind] < dp[prev]+1) dp[ind] = dp[prev] + 1;
            }
        }
        
        int ans = 1;
        for(auto it : dp) {ans = max(ans , it);};
        
        return ans;
    }
};