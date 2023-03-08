class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0 , j = 0;
        
        while(j < n){
            int cnt = 1;
            while(j < n-1 && nums[j] == nums[j+1]){
                j++;cnt++;
            }
            if(cnt >= 2){
                nums[i++] = nums[j];
                nums[i++] = nums[j++];
            }
            else nums[i++] = nums[j++];
        }
        
        return i;   
    }
};