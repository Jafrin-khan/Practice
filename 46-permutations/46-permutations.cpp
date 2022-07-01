class Solution {
public:
    
    void f(vector<vector<int>> & ans , vector<int> helper , vector<int> freq , vector<int>& nums){
        
        if(helper.size() == nums.size()){
            ans.push_back(helper);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(freq[i] != 1){
                helper.push_back(nums[i]);
                freq[i] = 1;
                f(ans,helper,freq,nums);
                freq[i] = 0;
                helper.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> helper;
        
        vector<int> freq(nums.size(),0);
        
        f(ans , helper, freq , nums);
        
        return ans;
    }
};