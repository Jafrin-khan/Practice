class Solution {
public:
    
    // https://leetcode.com/problems/subarray-product-less-than-k/discuss/3131119/Sliding-Window-Approach-oror-With-simple-mathematics-trick-oror-C%2B%2B
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int left = 0 ,right = 0;
        int ans = 0 , prod = 1;
        
        while(right < n){
            prod*=nums[right];
            while(left <= right && prod >= k){
                prod/=nums[left++];
            }
            if(prod < k) ans += (right-left+1);
            right++;
        }
        return ans;
    }
};