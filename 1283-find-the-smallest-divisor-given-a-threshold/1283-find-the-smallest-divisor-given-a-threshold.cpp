class Solution {
public:
    
    int isValid(int divisor , int threshold , vector<int>& nums){
        int div = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]%divisor != 0) div += nums[i]/divisor + 1;
            else div += nums[i]/divisor;
        }
        return div <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());
        int ans;
        
        while(low <= high){
            int mid = (low + high)/2;
             
            if(isValid(mid , threshold , nums)){
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        
        return ans;
    }
};