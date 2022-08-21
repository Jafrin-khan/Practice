class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        int curr = nums[0];
        int maxSum = nums[0];
        
        for(int i = 0 ; i < nums.size()-1 ; i++){
            
            
            if(curr < 0){
                curr = 0;
            }
            curr += nums[i+1];
            maxSum = max(curr , maxSum);
        }
        
        return maxSum;
        
    }
};