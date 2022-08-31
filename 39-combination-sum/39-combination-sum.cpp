class Solution {
public:
    
    vector<vector<int>> ans;
    
    void f(int ind , vector<int>& nums , vector<int>& helper , int target){
        
        if(ind == nums.size()){
            return;
        }
        
        if(target == 0){
            ans.push_back(helper);
            return;
        }
        
        f(ind+1 , nums , helper , target);
        
        if(target >= nums[ind]){
        helper.push_back(nums[ind]);
        f(ind, nums , helper , target - nums[ind]);
        helper.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> helper;
        f(0 , nums , helper , target);
        
        return ans;
        
    }
};