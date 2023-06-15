class Solution {
public:
    
    bool f(int ind , int k, vector<int> &arr , vector<vector<int>>& dp){
    
    if(ind == 0) return arr[0] == k;
    
    if(arr[ind] == k) return true;
    if(dp[ind][k] != -1) return dp[ind][k];
    
    int notTake = f(ind-1 , k , arr , dp);
    int take = false;
    if (k - arr[ind] >= 0) {
      take = f(ind - 1, k - arr[ind], arr, dp);
    }

    return dp[ind][k] = take || notTake;
}
    
    bool canPartition(vector<int>& nums) {
         
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) sum += nums[i];
        
        if(sum%2 != 0) return false;
        
        sum/=2;
        
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        return f(n-1 , sum , nums , dp);
    }
};