class Solution {
public:
    //https://www.youtube.com/watch?v=8ci8WfQ6cns
    /*
    TC = O(N)
    SC = O(1)
    */
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i = 0;
        int n = nums.size();
        vector<int> ans;
        
        while(i < n){
            int gotoNum = abs(nums[i]);
            if(nums[gotoNum-1] < 0) ans.push_back(gotoNum);
            else{
                nums[gotoNum-1] = -1*nums[gotoNum-1];
            }
            i++;
        }
        return ans;
    }
};