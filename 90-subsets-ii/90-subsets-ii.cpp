class Solution {
public:
    
    void f(int ind , vector<int>& nums , set<vector<int>> &ans , vector<int>helper){
        
        if(ind == nums.size()){
            sort(helper.begin(),helper.end());
            ans.insert(helper);
            return;
        }
        
        //notpick
        f(ind+1 , nums , ans , helper);
        //pick
        helper.push_back(nums[ind]);
        f(ind+1 , nums , ans , helper);
        helper.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> helper;
        
        f(0 , nums , st , helper);
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
    }
};