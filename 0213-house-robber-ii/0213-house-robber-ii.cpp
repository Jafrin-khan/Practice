class Solution {
public:
    //03-06-2023
    int f(int ind , vector<int>& nums , vector<int>& dp){
    if(ind < 0) return 0;
    if(ind == 0) return nums[0];

    if(dp[ind] != -1) return dp[ind];
    
    int notTake = f(ind-1 , nums , dp);
    int take = f(ind-2 , nums , dp) + nums[ind];

    return dp[ind] = max(take , notTake);
}

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);

        vector<int> dp(n , -1);
        
        vector<int> v1;
        vector<int> v2;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(i != 0) v1.push_back(nums[i]);
            if(i != n-1) v2.push_back(nums[i]);
        }
        n--;
        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);
        return max(f(n-1 , v1 , dp1) , f(n-1 , v2 , dp2));
    }
};