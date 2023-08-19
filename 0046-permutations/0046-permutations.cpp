class Solution {
public:
    
/* // Approach 1
// Time Complexity:  N! x N

// Space Complexity:  O(N)
   
    void f(vector<int>& nums , vector<vector<int>>& ans , vector<int> helper , vector<int>& freq){
        if(helper.size() == nums.size()){
            ans.push_back(helper);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){*************************************************
            if(freq[i] == 0){
                freq[i] = 1;
                helper.push_back(nums[i]);
                f(nums , ans , helper , freq);
                helper.pop_back();
                freq[i] = 0;j
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
    */
    
    //APPROACH 2
//     Time Complexity: O(N! X N)

//     Space Complexity: O(1)
    
    void f(int ind , vector<int>& nums , vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind ; i < nums.size() ; i++){
           swap(nums[i] , nums[ind]);
           f(ind+1 , nums , ans);
           swap(nums[i] , nums[ind]);
        }
    }
    
        vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        f(0, nums , ans);
        
        return ans;
    }
};

//   [1 2 3]
   
// [1 3  2]
//   [1 , 1 , 1]
