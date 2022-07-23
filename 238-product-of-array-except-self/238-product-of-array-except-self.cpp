class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int totProd = 1;
        int check = 0;
        
        int cntZeros = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0){
                check = 1;
                cntZeros++;
                continue;
            }
            
            totProd*=nums[i];
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(check){
                
                if(cntZeros >= 2){
                    nums[i] = 0;
                }
                else if(nums[i] != 0){
                    nums[i] = 0;
                }
                
                else if(nums[i] == 0){
                    nums[i] = totProd;
                }
            }
            
            else{
                int toPush = totProd/nums[i];
                nums[i] = toPush;
            }
        }
        
        return nums;
        
    }
};