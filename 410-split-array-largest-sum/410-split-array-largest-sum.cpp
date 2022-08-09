class Solution {
public:
    
   int isPossible(vector<int>& nums, int midSum){
        
        int sum = 0;
        int subarrays = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(sum + nums[i] > midSum){
                subarrays++;
                sum = nums[i];
                
               
            }
            
            else{
                 sum += nums[i];
            }
        }
       
       subarrays++;
        
      return subarrays;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int totSum = 0;
        int maxSum = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            totSum += nums[i];
            maxSum = max(maxSum , nums[i]);
        }
        
        int cnt = 0;
        int lowSum = maxSum;
        int highSum = totSum;
        
        while(lowSum <= highSum){
            
            int midSum = (lowSum+highSum)/2;
            int subarrays = isPossible(nums , midSum);//returns no of subarrrays
            if(subarrays <= m){
                  cnt = midSum;
                  highSum = midSum-1;
            }
            
            else{
                lowSum = midSum+1;
            }
        }
        
        return cnt;
        
    }
};