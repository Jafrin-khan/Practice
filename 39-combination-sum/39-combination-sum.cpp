class Solution {
public:
    
      void f(int ind , vector<int>& nums , set<vector<int>> &ans , vector<int>helper , int target){
           if(target == 0){
            sort(helper.begin(),helper.end());
            ans.insert(helper);
            }
        
        if(ind == nums.size()){
            return;
        }
        
        //notpick
        f(ind+1 , nums , ans , helper , target);
        //pick
        helper.push_back(nums[ind]);
        if(target >= nums[ind]){
        f(ind, nums , ans , helper , target - nums[ind]);
        }
        helper.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> helper;
        
        f(0 , nums , st , helper , target);
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};