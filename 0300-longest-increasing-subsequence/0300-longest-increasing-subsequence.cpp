class Solution {
public:
    /*
     //Recursion
    //TC = O(2^N)
    //SC = O(N)
    int f(int ind , int prev_ind , int n , vector<int>& nums){
        if(ind == n) return 0;
        
        int take = 0;
        int notTake = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]) take = 1 + f(ind+1 , ind , n , nums);
        notTake = 0 + f(ind+1 , prev_ind , n , nums); // ye statement else mai ni daalni...V.IMP to remember
        
        return max(take , notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        return f(0 , -1 , n , nums);
    }*/
    
    
    //Memoised
    //TC = O(N*N)
    //SC = O(N/N) + O(N)
    int f(int ind , int prev_ind , int n , vector<int>& nums , vector<vector<int>>& dp){
        if(ind == n) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        int take = 0;
        int notTake = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]) take = 1 + f(ind+1 , ind , n , nums , dp);
        notTake = 0 + f(ind+1 , prev_ind , n , nums , dp); // ye statement else mai ni daalni...V.IMP to remember
        
        return dp[ind][prev_ind+1] = max(take , notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return f(0 , -1 , n , nums , dp);
    }
};