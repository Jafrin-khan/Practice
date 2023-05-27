class Solution {
public:
    
    void f(int ind , vector<int>& nums , vector<int> helper , set<vector<int>>& st){
        if(ind < 0){
            sort(helper.begin() , helper.end());
            st.insert(helper);
            return;
        }
        
        //take
        helper.push_back(nums[ind]);
        f(ind-1 , nums , helper , st);
        helper.pop_back();
        
        //notTake
        f(ind-1 , nums , helper , st);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> helper;
        set<vector<int>> st;
        
        f(n-1 , nums , helper , st);
        
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};