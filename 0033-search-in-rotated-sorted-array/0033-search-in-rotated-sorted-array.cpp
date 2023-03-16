class Solution {
public:
    /*
    TC = O(logN)
    SC = O(1)
    */
    
    /*
        /*
    
     nums = [4,5,6,7,0,1,2], target = 0
            0  1 2 3 4 5 6
            
      
     l = 0;
     h = 6;
     m = 3;
     
     4 <= 7 yes , 4 <= 0 no , hence l = 4
     
     l = 4;
     h = 6;
     m = 5;
     
     
     0 <= 1 no , 1 <= 0 no , hence h =4
     
     l = 4;
     h = 4;
     m = 4;
     
     0 == 0 return 4;
     
     
    */
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(target == nums[mid]) return mid;
            
            //when left side is sorted
            if(nums[low] <= nums[mid]){
               
                if(nums[low] <= target && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            //when right side is sorted
            else{
                
                if(nums[mid] <= target && nums[high] >= target) low = mid+1;
                else high = mid-1;
            }
            
        }
        
        return -1;
    }
};