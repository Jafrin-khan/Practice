class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }
            
            else{
                high = mid-1;
            }
            
            
        }
        
        return nums[low];
        
    }
};