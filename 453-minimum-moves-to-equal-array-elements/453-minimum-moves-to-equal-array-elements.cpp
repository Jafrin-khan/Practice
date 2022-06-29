class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int mini = nums[0];
        
        int cnt = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }
         
        for(auto x : nums){
            cnt += x - mini;
        }
        
        return cnt;
        
    }
};