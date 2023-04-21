class Solution {
public:
    
    //see submission of 01/09/2023
    
    int maxSubArray(vector<int>& nums) {
        
        int currSum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            
            if(currSum < 0) currSum = 0;
            currSum += nums[i];
            maxSum = max(maxSum , currSum);
        }
        
        return maxSum;
    }
};