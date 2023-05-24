class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans = 0;
        int track = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1) track++;
            else track = 0;
            ans = max(ans , track);
        }
        return ans;
    }
};