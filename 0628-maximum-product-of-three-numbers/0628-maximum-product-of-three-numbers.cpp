class Solution {
public:
    
    /*
    TC = O(NLogN)
    SC = O(1)
    */
    
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int ans = max(nums[0]*nums[1]*nums[nums.size()-1] , nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
        
        return ans;
    }
};