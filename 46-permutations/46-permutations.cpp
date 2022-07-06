class Solution {
public:
     vector<vector<int>> ans;
    void f(int ind , vector<int>& nums , vector<int> helper , vector<int>& marked){
        
         if(helper.size() == nums.size()){
                ans.push_back(helper);
                return;
        }
      
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(marked[i] != -1){
                helper.push_back(nums[i]);
                marked[i] = -1;
                f(ind + 1 , nums , helper , marked);
                helper.pop_back();
                marked[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
       
        vector<int> marked(nums.size() , 1);
        vector<int> helper;
        f(0 , nums , helper , marked);
        
        return ans;
    }
};