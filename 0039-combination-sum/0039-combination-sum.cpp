class Solution {
public:
    
    void f(int ind , int k , vector<int>& helper , set<vector<int>>& st , vector<int>& nums){
        
        if(ind < 0){
            if(k == 0) {
            st.insert(helper);
        }
            return;
        }
        
        
        
        //take
        if(k >= nums[ind]){
        helper.push_back(nums[ind]);
        f(ind , k - nums[ind] , helper , st , nums);
        helper.pop_back();
        }
        
        //notTake
        f(ind-1 , k , helper , st , nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        set<vector<int>> st;
        vector<int> helper;
        f(n-1 , target ,helper, st , nums);
        
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};