class Solution {
public:
    
    //recursing , memo , tabulated pichle submission m hai explanation k saath
    
    //EASY TRICK FOR LIS WITH O(N) SC
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev <= i-1 ; prev++){
                if(nums[prev] < nums[i]) dp[i] = max(dp[i] , 1 + dp[prev]);
            }
        }
        
        for(int i = 0 ; i < n ; i++) ans = max(ans , dp[i]);
        
        return ans;
    }
};