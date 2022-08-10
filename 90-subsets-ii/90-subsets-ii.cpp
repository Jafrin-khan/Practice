class Solution {
public:
    
    set<vector<int>> st;
    void f(int ind , vector<int>& nums ,  vector<int> helper){
        
        if(ind == nums.size()){
            sort(helper.begin() , helper.end());
            st.insert(helper);
            return;
        }
        
       //not taken
        f(ind + 1 , nums , helper);
        
        //taken
        helper.push_back(nums[ind]);
        f(ind + 1 , nums , helper);
        helper.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        
        vector<vector<int>> ans;
        vector<int> helper;
        
        f(0 , nums , helper); 
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
        
        
        
    }
};