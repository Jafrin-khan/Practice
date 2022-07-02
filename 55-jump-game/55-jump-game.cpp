class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int farthest = 0;
        
        for(int i = 0 ; i < nums.size()-1 ; i++){
            farthest = max(farthest , i + nums[i]);
            if(i == farthest && nums[i] == 0){
                return false;
            }
        }
        
        return true;
        
    }
};