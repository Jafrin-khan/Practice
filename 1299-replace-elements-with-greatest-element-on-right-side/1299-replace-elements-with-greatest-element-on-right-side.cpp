class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
    
        vector<int> v;
        reverse(nums.begin(),nums.end());
         int maxi = nums[0];
        v.push_back(-1);
        for(int i = 1 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i-1]);
            v.push_back(maxi);
        }
         reverse(v.begin(),v.end());
        return v;
        
    }
};