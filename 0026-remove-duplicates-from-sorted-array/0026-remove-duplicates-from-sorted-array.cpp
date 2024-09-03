class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        
        int n = nums.size();
        
        if(n == 1) return 1;
        
        int currInd = 0;
        int i = 0;
        int ans = 1;
        
        while(i < n){
            if(nums[i] == nums[currInd]){
                while(i < n && nums[i] == nums[currInd]) i++;
            }
            else 
            {nums[++currInd] = nums[i++];
            ans++;
            }
        }
        
        return ans;
    }
};