class Solution {
public:
    
    void f(int ind , int k , vector<int> helper , vector<vector<int>>& ans , vector<int> nums){
        if(k == 0){
            ans.push_back(helper);
            return;
        }
        
        for(int i = ind ; i < nums.size() ; i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            
            if(k >= nums[i]){
            helper.push_back(nums[i]);
            f(i+1 , k - nums[i] , helper , ans , nums);
            helper.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        vector<int> helper;
        vector<vector<int>> ans;
        
        f(0 , k , helper , ans , nums);
        
        return ans;
    }
};