class Solution {
public:
    /*
    TC = O(N) + O(NlogN) ~ O(NlogN)
    SC = O(1)
    */
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        
        int i = 0;
        int j = n-1;
        
        while(i <= j){
            if(pow(nums[i],2) >= pow(nums[j],2)) ans.push_back(pow(nums[i++],2));
            else ans.push_back(pow(nums[j--],2));
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};