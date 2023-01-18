class Solution {
public:
    
    /*
    TC = O(N)
    SC = O(1)
    */
    void sortColors(vector<int>& nums) {
        
        int i = 0;
        int m = 0;
        int j = nums.size()-1;
        
        while(m <= j){
            
           if(nums[m] == 1){
               m++;
           }
            
           else if(nums[m] == 0){
               swap(nums[i++] , nums[m++]);
           }
            
           else{
               swap(nums[m] , nums[j--]);
           }
        }
        
        
    }
};