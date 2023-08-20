class Solution {
public:
    vector<vector<int>> ans;
    
    void f(int ind , vector<int> helper , vector<int>& nums){
        ans.push_back(helper);
           
        for(int i = ind ; i < nums.size() ; i++){
            
            if(i != ind && nums[i] == nums[i-1]){
                continue;
            }
            
            helper.push_back(nums[i]);
            f(i+1 , helper , nums);
            helper.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<int> helper;
        f(0 , helper , nums);
        
        return ans;
        
    }
};