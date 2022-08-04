class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if(nums.size() == 1){
            return;
        }
        
        int start = 0;
        int end = 0;
        
        while(end < nums.size()){
            
            if(nums[end] != 0){
                swap(nums[start++], nums[end++]);
            }
            
            else{
                end++;
            }
        }
        
        
        
    }
};