class Solution {
public:
    
    
    void f(int ind , int target , vector<int>& nums, vector<int> helper , set<vector<int>>& st){
        
        if(target == 0){
            sort(helper.begin() , helper.end());
            st.insert(helper);
            
 
        }
        
        if(ind == nums.size()){
            return;
        }
        
        //notTaken
        f(ind+1 , target , nums , helper , st);
        //taken
        helper.push_back(nums[ind]);
        if(target >= nums[ind]){
        f(ind , target - nums[ind] , nums , helper , st);
        }
        helper.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> helper;
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        f(0, target , nums , helper , st);
        
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
        
        
        
        
    }
};