class Solution {
public:

 
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
        int len;
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
                 //not taken
                len = 0 + dp[ind+1][prev_ind+1];

                //taken
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                len = max(len , 1 + dp[ind+1][ind+1]);
                }

                dp[ind][prev_ind+1] = len;
                    }
        }
        return dp[0][-1+1];
        
    }
};