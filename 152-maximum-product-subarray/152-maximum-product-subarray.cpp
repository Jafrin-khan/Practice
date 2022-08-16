class Solution {
public:
    
    int f(int n , int com , vector<int>& nums , unordered_map<int,int>dp[]){
        
        if(n < 0){
            return com;
        }
        
         if(dp[n].find(com)!=dp[n].end())return dp[n][com];
        
        int notTake = f(n-1 , com*nums[n] , nums , dp);
        int take = f(n-1 , nums[n] , nums , dp);
        
        int ans = max({take , notTake , com});
        
        return dp[n][com] = ans;
    }
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
       unordered_map<int,int>dp[n];
        
        return f(n-2 , nums[n-1] , nums , dp);
        
        
    }
};