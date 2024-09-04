class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        while(j < n){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
            j++;
        }
        
        while(i < n) nums[i++] = 0;
    }
};