class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int prod = 1;
        int maxLeft = -1e9;
        
        bool isZero = false;
        
        for(int i = 0 ; i < n ; i++){
            prod*=nums[i];
            if(nums[i] == 0){
                isZero = true;
                prod = 1;
                continue;
            }
            
            maxLeft = max(maxLeft ,prod);
        }
        
        prod = 1;
        int maxRight = -1e9;
        for(int i = n-1 ; i >= 0 ; i--){
            prod*=nums[i];
            if(nums[i] == 0){
                isZero = true;
                prod = 1;
                continue;
            }
            
            maxRight = max(maxRight , prod);
        }
        
        if(isZero) return max({maxLeft , maxRight , 0});
        
        return max(maxLeft , maxRight);
        
    }
};