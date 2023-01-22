class Solution {
public:
    
    /*
    TC = O(N)
    SC = O(1)
    */
    int maxProduct(vector<int>& nums) {
        
        int maxProduct = 1;
        int minProduct = 1;
        int ans = -1e9;
        
        for(int i = 0 ; i < nums.size() ; i++){
            //for considering -ve*-ve as well
            int temp = maxProduct;
            maxProduct = max({temp*nums[i] ,minProduct*nums[i] , nums[i]});
            minProduct = min({temp*nums[i] , minProduct*nums[i], nums[i]});
            ans = max(ans , maxProduct);
        }
        
        return ans;
        
    }
};