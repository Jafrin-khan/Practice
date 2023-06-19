class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int ind = 0;
        int i = 0;
        
        while(i < nums.size()){
            nums[ind++] = nums[i++];
            while(i > 0 && i < nums.size() && nums[i] == nums[i-1]) i++;  
        }
        
        return ind;
    }
};