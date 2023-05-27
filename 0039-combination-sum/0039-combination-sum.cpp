class Solution {
public:
    
    void f(int ind , int k , vector<int>& helper , vector<vector<int>>& ans , vector<int>& nums){
        
        if(ind < 0){
            if(k == 0) {
            ans.push_back(helper);
        }
            return;
        }
        
        //take
        if(k >= nums[ind]){
        helper.push_back(nums[ind]);
        f(ind , k - nums[ind] , helper , ans , nums);
        helper.pop_back();
        }
        
        //notTake
        f(ind-1 , k , helper , ans , nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
         vector<vector<int>> ans;
        vector<int> helper;
        f(n-1 , target ,helper, ans , nums);
        
       
        
        return ans;
    }
};