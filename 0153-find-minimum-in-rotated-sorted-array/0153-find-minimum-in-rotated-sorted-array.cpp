class Solution {
public:
    /*
    TC = O(logn)
    SC = O(1)
    */
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0;
        int high = n-1;
        
        while(low < high-1){
            int mid = (low + high)/2;
            
            if(nums[mid] < nums[high]) high = mid;
            else low = mid;
        }
        
        return min(nums[low] , nums[high]);
    }
};