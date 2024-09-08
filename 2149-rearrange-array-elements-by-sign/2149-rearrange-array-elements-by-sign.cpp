class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> v1;
        vector<int> v2;
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        
        int ind1 = 0;
        int ind2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(i%2) nums[i] = v2[ind2++];
            else nums[i] = v1[ind1++];
        }
        
        return nums;
        
    }
};