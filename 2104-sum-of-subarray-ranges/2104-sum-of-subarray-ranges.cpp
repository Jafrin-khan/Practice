class Solution {
public:
    
   
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        
        long long int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            int s = nums[i];
            int l = nums[i];
            for(int j = i+1 ; j < n ; j++){
                s = min(s , nums[j]);
                l = max(l , nums[j]);
                
                long long diff = l - s;
                ans += diff;
            }
        }
        return ans;
    }
};