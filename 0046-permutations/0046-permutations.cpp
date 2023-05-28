class Solution {
public:
    
    /*
Time Complexity:  N! x N

Space Complexity:  O(N)
    */
    void f(vector<int>& nums , vector<vector<int>>& ans , vector<int> helper , vector<int>& freq){
        if(helper.size() == nums.size()){
            ans.push_back(helper);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(freq[i] == 0){
                freq[i] = 1;
                helper.push_back(nums[i]);
                f(nums , ans , helper , freq);
                helper.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> helper;
        
        vector<int> freq(nums.size() , 0);
        
        f(nums , ans , helper , freq);
        
        return ans;
    }
};