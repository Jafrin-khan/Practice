class Solution {
public:
    
    int f(int ind , vector<int>& nums ,  vector<int>& dp){
        
        if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int notTake = f(ind-1 , nums , dp);
        int take = nums[ind] + f(ind-2 , nums , dp);
        
        return dp[ind] = max(take , notTake);
    }
    
    int rob(vector<int>& nums) {
                
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);
        
        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);
        
        vector<int> n1 , n2;
        for(int i = 0 ; i < n ; i++){
            if(i != 0) n1.push_back(nums[i]);
            if(i != n-1) n2.push_back(nums[i]);
        }
        
        return max(f(n1.size()-1 , n1 , dp1) , f(n2.size()-1 , n2 , dp2));
    }
};