class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i = 0;
        int j = nums.size()-1;
        
        while(i < j){
            if(nums[i]%2 == 0){
                i++;
            }
            
            else{
                break;
            }
        }
        
        while(i < j){
            if(nums[j]%2 == 1){
                j--;
            }
            
            else{
                break;
            }
        }
        
        while(i < j){
            
            if(nums[i]%2 == 1 && nums[j]%2 == 0){
                swap(nums[i++],nums[j--]);
            }
            
            else if(nums[i]%2 == 0){
                i++;
            }
            
            else{
                j--;
            }
        }
        
        return nums;
    }
};