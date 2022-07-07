class Solution {
public:
    
    int longestOnes(vector<int>& nums, int k) {
        
        int start = 0;
        int end = 0;
        
        int n = nums.size();
        int ans = 0;
        
        int flips = 0;
        
        while(end < n){
            
            if(nums[end] == 1){
                ans = max(ans ,end-start+1);
                end++;
            }
            
            else{
                if(flips < k){
                    flips++;
                    ans = max(ans ,end-start+1);
                    end++;
                }
                
                else{
                    while(flips >= k){
                        if(nums[start] != 1){
                            flips--;
                        }
                        
                        start++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};