class Solution {
public:
    
    vector<vector<int>> ans;
    
    void f(vector<int>& nums , vector<int> helper , vector<int> freq){
        
        if(helper.size() == nums.size()){
            ans.push_back(helper);
            return;
        }
        
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(!freq[i]){
                freq[i] = 1;
                helper.push_back(nums[i]);
                f(nums , helper , freq);
                freq[i] = 0;
                helper.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> helper;
        vector<int> freq(nums.size() , 0);
        
        f(nums , helper , freq);
        
        return ans;
        
    }
};