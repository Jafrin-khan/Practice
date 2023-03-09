class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        
        int start = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != sorted[i]){ start = i;break;}
        }
        int end = -1;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            if(nums[i] != sorted[i]) {end = i ; break;}
        }
        
        if(start == -1 && end == -1) return 0;
        return end-start+1;
    }
};