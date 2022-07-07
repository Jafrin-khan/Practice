class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return true;
        }
        
        int ind = 1;
        while(ind < nums.size()-1 && (nums[ind] == nums[ind-1])){
            ind++;
        }
        
        if(nums[ind] < nums[ind-1] ){
            
            int i = 1;
            while(i < nums.size()){
                if(nums[i] > nums[i-1]){
                    return false;
                }
                i++;
            }
        }
        
        else{
            
            int i = 1;
            while(i < nums.size()){
                if(nums[i] < nums[i-1]){
                    return false;
                }
                i++;
            }
            
        }
        
        return true;
    }
};