class Solution {
public:
    
    /*
    TC = O(N) + O(N)
    SC = O(1)
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1;
        int cntZero = 0;
        int zind;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0){
                cntZero++;
                zind = i;
                continue;
            }
            prod*=nums[i];
        }
        
        if(cntZero == 1){
            
            for(int i = 0 ; i < nums.size() ; i++){
                    nums[i] = 0;
                }
            
            nums[zind] = prod;
            return nums;
                
            }
            
           
        
        if(cntZero > 1){
            for(int i = 0 ; i < nums.size() ; i++){
                    nums[i] = 0;
                }
            return nums; 
        }
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = prod/nums[i];
        }
        
        return nums;
        
    }
};