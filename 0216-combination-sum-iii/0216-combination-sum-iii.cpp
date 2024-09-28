class Solution {
public:
    
    void f(int ind , vector<int> helper , vector<vector<int>>& ans , vector<int> nums , int target , int k){
        
         
        if(target == 0 && helper.size() == k){
            ans.push_back(helper);
            return;
        }
        
        if(ind < 0) return;
        
        //take
        helper.push_back(nums[ind]);
        f(ind-1 , helper, ans , nums , target - nums[ind] , k);
        helper.pop_back();
        
        //notTake
        f(ind-1 , helper , ans , nums , target , k);
    }
    
    vector<vector<int>> combinationSum3(int k, int target) {
        
        vector<vector<int>> ans;
        vector<int> helper;
        
        vector<int> nums = {1 , 2 , 3 , 4 , 5 ,6 ,7 ,8 ,9};
        f(nums.size()-1 , helper , ans ,nums , target , k);
        
        return ans;
        
    }
};