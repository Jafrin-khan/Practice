class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int start = 0;
        int mid = 0;
        int end = n-1;
        
        while(mid <= end){
            
            if(nums[mid] == 0){
                swap(nums[start++] , nums[mid++]);
            }
            
            else if(nums[mid] == 1){
                mid++;
            }
            
            else{
                swap(nums[end--] , nums[mid]);
            }
            
            
        }
        
    }
    
    //TC = O(n)
};