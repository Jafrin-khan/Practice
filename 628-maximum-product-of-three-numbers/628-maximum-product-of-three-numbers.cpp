class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        if(nums.size() < 3){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();

        int y = nums[0]*nums[1]*nums[n-1];
        int z = nums[n-1]*nums[n-2]*nums[n-3];
       
        
        return max({y,z});
        
    }
};