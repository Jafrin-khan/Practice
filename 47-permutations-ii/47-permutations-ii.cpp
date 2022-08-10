class Solution {
public:
    set<vector<int>> st;
    void f(vector<int>& vis , vector<int> helper , vector<int>& nums){
        
        if(helper.size() == nums.size()){
            st.insert(helper);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(!vis[i]){
                
                vis[i] = 1;
                helper.push_back(nums[i]);
                f(vis , helper , nums);
                helper.pop_back();
                vis[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> vis(nums.size(),0);
        vector<int> helper;
        
        f(vis , helper , nums);
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};