class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int smallestNum = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            smallestNum = min(smallestNum , nums[i]);
        }
        
        int cnt = 0;
        for(auto x : nums){
            cnt  += (x - smallestNum);
        }
        
        return cnt;
        
    }
};