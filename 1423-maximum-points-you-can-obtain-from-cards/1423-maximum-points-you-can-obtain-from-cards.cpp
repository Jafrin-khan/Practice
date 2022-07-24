class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();
        
        int totSum = 0;
        int leftOverSum = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(i < (n-k)){
                leftOverSum+=nums[i];
            }
            totSum += nums[i];
        }
        
        
        int left = 0;
        int right = n - k;
        ans = totSum - leftOverSum;
        while(right < n){
            
            leftOverSum -= nums[left++];
            leftOverSum += nums[right++];
            
            ans = max(ans,totSum - leftOverSum);
            
        }
        
        return ans;
        
    }
};