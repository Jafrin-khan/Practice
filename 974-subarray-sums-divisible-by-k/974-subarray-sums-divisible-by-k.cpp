class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        
        mp[0] = 1;
        int sum = 0;
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            sum += nums[i];
            int r = (sum%k + k)%k;
            
            if(mp.find(r) != mp.end()){
                ans+=mp[r];
            }
            
            mp[r]++;
            
        }
        
        return ans;
        
    }
};