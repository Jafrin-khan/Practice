class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        
        int i = 0;
        int j = n-1;
        int ind = n-1;
        while(i <= j){
            if(pow(nums[i],2) >= pow(nums[j],2)) ans[ind--] = (pow(nums[i++],2));
            else ans[ind--] = (pow(nums[j--],2));
        }
       
        return ans;
    }
};