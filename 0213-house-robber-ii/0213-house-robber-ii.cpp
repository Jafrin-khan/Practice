class Solution {
public:
    
    //diff from house robberI as here we are given circular array
    
    int f(int ind , vector<int>& nums , vector<int>& dp){
         
        if(ind < 0){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int notTaken = 0 + f(ind - 1 , nums , dp);
        int taken = nums[ind] + f(ind - 2 , nums , dp);
        
        return dp[ind] = max(taken,notTaken);
        
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
       
        if(n == 1){
            return nums[0];
        }
        vector<int> arr1;
        vector<int> arr2;
        
        
        for(int i = 0 ; i < n ; i++){
            
            if(i != 0){
                arr1.push_back(nums[i]);
            }
            
            if(i != n-1){
                arr2.push_back(nums[i]);
            }
        }
        vector<int> dp1(arr1.size()+1 , -1);
        
        int ans1 = f(arr1.size()-1 , arr1 , dp1);
         vector<int> dp2(arr2.size()+1 , -1);
        int ans2 = f(arr2.size()-1 , arr2 , dp2);
        
        return max(ans1 , ans2);
         
    }
};