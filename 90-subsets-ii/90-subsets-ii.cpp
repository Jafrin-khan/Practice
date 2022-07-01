class Solution {
public:
    
    void f(int ind , vector<int>& nums , set<vector<int>>& st , vector<int> helper){
        
        if(ind == nums.size()){
            sort(helper.begin(),helper.end());
            st.insert(helper);
            return;
        }
        
        //not pick
        f(ind + 1 , nums , st , helper);
        //pick;
        helper.push_back(nums[ind]);
        f(ind + 1 , nums , st , helper);
        helper.pop_back();
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> st;
        vector<int> helper;
        vector<vector<int>> ans;
        
        f(0 , nums , st , helper);
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
    }
};