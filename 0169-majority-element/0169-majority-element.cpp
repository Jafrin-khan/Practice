class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        int cnt = 0;
        int ele = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            if(cnt == 0) {ele = nums[i]; cnt = 1;}
            else if(ele == nums[i]) cnt++;
            else cnt--;
        }
        
        cnt = 0;
        for(auto it : nums){
            if(it == ele) cnt++;
        }
        
        if(cnt >= (floor)(nums.size()/2)) return ele;
        return -1;
    }
};