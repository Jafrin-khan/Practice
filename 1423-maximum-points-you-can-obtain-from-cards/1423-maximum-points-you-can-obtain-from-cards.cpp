class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int bound = n - k;
        int toDel = 0;
        
        int tot = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            if(i < bound){
                toDel += nums[i];
            }
            tot += nums[i];
            
        }
        
        int score = tot-toDel;
        
        int ans = score;
        
        int left = 0;
        int right = n-k;
        
        while(right < n){
            
            score += nums[left++];
            score -= nums[right++];
            
            ans = max(ans , score);
            
            
        }
        
        return ans;
        
        
    }
};