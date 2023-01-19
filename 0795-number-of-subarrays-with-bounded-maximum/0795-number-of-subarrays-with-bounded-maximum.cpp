class Solution {
public:
    
    //BNY Mellon
    
    /*
    TC = O(N)
    SC = O(N)
    */
    
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        
        int n = nums.size();
        int cnt = 0;
        
        int left = -1;
        int right = -1;
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > R) left = i;
            if(nums[i] >= L) right = i;
            cnt += right-left;
        }
        
       return cnt;
        
    }
};