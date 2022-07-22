class Solution {
public:
    
    void f(int ind ,set<vector<int>>& st , vector<int> helper , vector<int>& nums){
        
        if(ind < 0){
            sort(helper.begin() , helper.end());
            st.insert(helper);
            return;
        }
        
        
        //notTake
        f(ind - 1 , st , helper , nums);
        //take
        helper.push_back(nums[ind]);
        f(ind - 1 , st , helper , nums);
        helper.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        set<vector<int>> st;
        vector<int> helper;
        
        f(nums.size()-1, st , helper , nums);
        
        vector<vector<int>> ans;
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};