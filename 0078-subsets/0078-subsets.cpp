class Solution {
public:
    
    void f(int ind , vector<vector<int>>& ans , vector<int>& helper , vector<int> nums){
        
        if(ind == nums.size()){
            ans.push_back(helper);
            return;
        }
        
        f(ind+1 , ans , helper , nums);
        helper.push_back(nums[ind]);
        f(ind+1 , ans , helper , nums);
        helper.pop_back();

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> helper;
        
        f(0 , ans , helper , nums);
        
        return ans;
    }
};