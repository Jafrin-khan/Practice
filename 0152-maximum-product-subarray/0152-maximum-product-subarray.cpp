class Solution {
public:
    //Approach 1 --> Brute force --> two for loops i is starting
    //TC = O(N^2) SC = O(1)
    
    /*
    //Approach 2
    //TC = O(N) + O(N)
    //SC = O(1)
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
    */
    
    //Approach 3 --> using Kadane's Algo
    //TC = O(N) SC = O(1)
    
     int maxProduct(vector<int>& nums) {
        
         int n = nums.size();
           
         int prod1 = nums[0] , prod2 = nums[0];
         int maxi = nums[0];
         
         for(int i = 1 ; i < n ; i++){
             int temp = max({nums[i] , prod1*nums[i] , prod2*nums[i]});
             prod2 = min({nums[i] , prod1*nums[i] , prod2*nums[i]});
             prod1 = temp;
             
             maxi = max(maxi , prod1);
         }
        
         return maxi;
    }
};