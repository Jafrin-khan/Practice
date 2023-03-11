class Solution {
public:
    
/* 2nd approch 
    if all elements are non-negative, we can use only one pass.
But for this problem, we have to go 2 passes to get sum first.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, left_sum = 0, right_sum = 0;
        while (i <= j) {
            if (i == j) {
                if (left_sum == right_sum) {
                    return i;
                }
                return -1;
            }
            
            if (left_sum <= right_sum) {
                left_sum += nums[i];
                ++i;
            } else {
                right_sum += nums[j];
                --j;
            }
        }
        return -1;
    }
};
    */
    int pivotIndex(vector<int>& nums) {
     int sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
        }
        for(int i =0;i<nums.size();i++){
            
            sum1-=nums[i];
            if(sum2==sum1)
            return i;
            sum2+=nums[i];
        }
        return -1;
    }
};