class Solution {
public:
    
   
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n , 0);
        
        dp[0] = nums[0];
         if(n>1){
            dp[1] = max(nums[0] , nums[1]);
        }
        for(int ind = 2 ; ind < n ; ind++){
            int notTake = dp[ind - 1];
            int take = nums[ind] + dp[ind - 2];
            
            dp[ind] = max(take , notTake);
        }
        return dp[n-1];
        
    }
};