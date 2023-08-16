class Solution {
public:
    
    void f(int ind , set<vector<int>>& st , vector<int>& nums , vector<int> helper){
        
        if(ind < 0){
            sort(helper.begin() , helper.end());
            st.insert(helper);
            return;
        }
        
        //take
        helper.push_back(nums[ind]);
        f(ind-1 , st , nums , helper);
        helper.pop_back();
        
        //notake
        f(ind-1 , st , nums , helper);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        vector<int> helper;
        f(n-1 , st , nums , helper);
        
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};