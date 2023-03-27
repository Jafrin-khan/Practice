class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int left = 0;
        int right = 0;
        
        int sum = 0;
        int ans = 1e9;
        
     while(right < n && left < n){
            if(sum < target) sum += nums[right++];
            else if(sum >= target){
                ans = min(ans , right-left);
                sum -= nums[left++];
            }
        }
     while(sum >= target && left < n){
            ans = min(ans , n-left);
            sum -= nums[left++];
        }
        if(ans == 1e9) return 0;
        
        return ans;
        
    }
};