class Solution {
public:
    
bool f(int ind , int k , vector<int> &nums , vector<vector<int>>& dp){
  if(k == 0) return true;
  if(ind == 0) return nums[ind] == k;

  if(dp[ind][k] != -1) return dp[ind][k];
 
  bool notTake = f(ind-1 , k , nums , dp);
  bool take = false;

  if(k >= nums[ind]) take = f(ind-1 , k - nums[ind] , nums , dp);

  return dp[ind][k] = take || notTake;
}
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        
        if(sum%2) return false;
        sum/=2;
        
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        
        return f(n-1 , sum , nums, dp);
    }
};