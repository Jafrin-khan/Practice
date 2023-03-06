class Solution {
public:

    /* // memoization
    int f(int ind , vector<int> &nums , vector<int>& dp){
    
    if(ind == 0){
        return nums[ind];
    }
    if(ind < 0){
        return 0;
    }
    
    if(dp[ind] != -1){
        return dp[ind];
    }
    int notTake = 0 + f(ind-1 , nums , dp);
    int take = nums[ind] + f(ind-2 , nums , dp);
    
    return dp[ind] = max(take , notTake);
        
}
   */ 
    
    // tabulation
    int f(int ind , vector<int> &nums , vector<int>& dp){
        
    dp[0] = nums[0];
        
    for(int ind = 1 ; ind < nums.size() ; ind++){
        int notTake = 0 + dp[ind-1];
        int take = nums[ind];
        
        if(ind > 1){
        take += dp[ind-2];
        }
        dp[ind] = max(take , notTake);
    }
        
    return dp[nums.size()-1];
        
}
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);
    
        vector<int> v1;
        vector<int> v2;
        
        for(int i = 0 ; i < n ; i++){
            if(i != 0) v1.push_back(nums[i]);
            if(i != n-1) v2.push_back(nums[i]);
        }
        
        vector<int> dp1(v1.size() , 0);
        int ans1 = f(v1.size()-1 , v1 , dp1);
        
        vector<int> dp2(v2.size() , 0);
        int ans2 = f(v2.size()-1 , v2 , dp2);
        
        return max(ans1 , ans2);
  
    }
};