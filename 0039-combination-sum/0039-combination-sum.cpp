class Solution {
public:
    
    void f(int ind , int k , vector<int>& nums, vector<int> helper , vector<vector<int>>& ans){
        
        if(ind < 0) return;
        
        if(k == 0){
            ans.push_back(helper);
            return;
        }
        
        //notTake
        f(ind-1 , k , nums , helper , ans);
        
        //take
        if(k >= nums[ind]){
        helper.push_back(nums[ind]);
        f(ind , k - nums[ind] , nums, helper , ans);
        helper.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        
        vector<int> helper;
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        f(nums.size()-1 , k , nums , helper , ans);
        
        return ans;
    }
};