class Solution {
public:
     vector<vector<int>> ans;
    
    void f(int ind , vector<int> &nums , vector<int> helper , vector<int>& freq){
        
        if(helper.size() == nums.size()){
            ans.push_back(helper);
            return;
        }
       
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(freq[i] != -1){
            helper.push_back(nums[i]);
            freq[i] = -1;
            f(i+1 , nums , helper , freq);
            helper.pop_back();
            freq[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> helper;
        vector<int> freq(nums.size(),0);
        f(0 , nums , helper , freq);
        
        return ans;
        
        
    }
};