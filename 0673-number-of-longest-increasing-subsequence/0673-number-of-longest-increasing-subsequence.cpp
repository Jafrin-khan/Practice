class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> cnt(n , 1);
        vector<int> dp(n , 1);
        
        int lis = 1;
        
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(nums[prev] < nums[ind] && dp[ind] < dp[prev]+1){
                    dp[ind] = dp[prev]+1;
                    cnt[ind] = cnt[prev];
                }
                
                else if(nums[prev] < nums[ind] && dp[ind] == dp[prev]+1){
                    dp[ind] = dp[prev]+1;
                    cnt[ind] += cnt[prev];
                }
                
                lis = max(lis , dp[ind]); 
            }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(dp[i] == lis){
                ans += cnt[i];;
            }
        }
        
        return ans;
        
    }
};