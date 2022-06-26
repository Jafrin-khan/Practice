class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int totalSum = 0;
        int n = nums.size();
        
        for(int i = 0 ; i < nums.size() ; i++){
            totalSum += nums[i];
        }
        
        int window = 0;
        int left = 0;
        int right = n-k;
        
        int i = 0;
        while(i < right){
            window += nums[i++];
        }
        
        int ans = totalSum - window;
        
        while(right < n){
            
            window -= nums[left++];
            window += nums[right++];
            
            ans = max(ans , totalSum - window);
        }
        
        return ans;
    }
};