class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxCurr = 0;
    
        for(int i = 0 ; i < nums.size() ; i++){
            int curr = 0;
            
            while(i < nums.size() && nums[i] == 1){
                curr++;
                i++;
            }
            
            maxCurr = max(maxCurr , curr);
            
        }
        
        return maxCurr;
        
    }
};