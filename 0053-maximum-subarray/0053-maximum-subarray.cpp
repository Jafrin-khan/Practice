class Solution {
public:
    
    /********************Kadan's Algo********************/
    
    /*
    TC = O(N)
    SC = O(1)
    */    
    //remeber difference b/w subarray , subset etc
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        
        //remember to initialise vars with nums[0] otherwise the algorithm wont work
        int currSum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            
            if(currSum < 0){
                currSum = 0;
            }
            
            currSum += nums[i];
            maxSum = max(maxSum , currSum);
        }
        
        return maxSum;
        
    }
};