class Solution {
public:
    
    bool f(int ind, int k , vector<int>& nums , vector<vector<int>>& dp){
        
        if(k == 0){
            return true;
        }
        
        if(ind == 0){
           return nums[0] == k; 
        }
        
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
            
        
        bool notTake = f(ind - 1 , k , nums , dp);
        bool take = false;
        if(k >= nums[ind]){
            take = f(ind-1 , k - nums[ind] , nums , dp);
        }
        
        return dp[ind][k] = take || notTake;    
    }
    
    bool canPartition(vector<int>& nums) {
        
        int totSum = 0;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            totSum += nums[i];
        }
        
        if(totSum%2 != 0){
            return false;
        }
        
        int sum = totSum/2;
        vector<vector<int>> dp(n , vector<int>(sum+1,0));
        
        for(int ind = 0 ; ind < n ; ind++){
            dp[ind][0] = 1;
        }
           if(nums[0] <= (sum)){
            dp[0][nums[0]] = 1;
        }
        for(int ind = 1 ; ind < n ; ind++){
            for(int k = 1 ; k <= sum ; k++){

                bool notTake = dp[ind - 1][k];
                bool take = false;
                if(k >= nums[ind]){
                    take = dp[ind-1][k - nums[ind]];
                }

                dp[ind][k] = take || notTake;  
            }
        }
        return dp[n-1][sum];
    }
};