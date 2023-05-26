class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
             int toFind = target - nums[i];
             if(mp.find(toFind) != mp.end()){
                 ans = {mp[toFind] , i};
                 break;
             }
            
             mp[nums[i]] = i;
        }
        
        return ans;
        
    }
};