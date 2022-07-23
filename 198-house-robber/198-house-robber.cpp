class Solution {
public:
    
    

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n , 0);
        
        if(n == 1){
            return nums[0];
        }
        
        if(n == 2){
            return max(nums[0] , nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);
        
        for(int ind = 2 ; ind < n ; ind++){
            int notTaken = 0 + dp[ind - 1];
            int taken = INT_MIN;
            taken = nums[ind] + dp[ind - 2];

            dp[ind] = max(taken , notTaken);
        }
        
        return dp[n-1];
        
    }
};
