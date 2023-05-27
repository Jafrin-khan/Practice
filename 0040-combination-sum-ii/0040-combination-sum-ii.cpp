class Solution {
public:
    
    void f(int ind , int k , vector<vector<int>>& ans , vector<int> helper , vector<int>& nums){
       
        if(k == 0) {
            ans.push_back(helper);
            return;
        }
        
        for(int i = ind ; i < nums.size() ; i++){
            
            if(i > ind && nums[i] == nums[i-1]) continue;
            
            if(k < nums[i]) break;
            
            helper.push_back(nums[i]);
            f(i+1 , k - nums[i] , ans , helper , nums);
            helper.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        vector<vector<int>> ans;
        vector<int> helper;
        f(0 , target , ans , helper , nums);
        
        return ans;
    }
};