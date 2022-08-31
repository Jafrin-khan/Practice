class Solution {
public:
    
    vector<vector<int>> ans;
    void f(int ind , vector<int>& nums, int target , vector<int> helper){
        
        
        if(target == 0){
            ans.push_back(helper);
            return;
        }
        
        for(int i = ind ; i < nums.size() ; i++){
            
            if(i != ind && nums[i] == nums[i-1]){
                continue;
            }
            
            if(target >= nums[i]){
            helper.push_back(nums[i]);
            f(i + 1 , nums , target - nums[i] , helper);
            helper.pop_back();
            }
            
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        vector<int> helper;
        sort(nums.begin() , nums.end());
        f(0 , nums , target , helper);
        
        return ans;
        
        
    }
};