class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        vector<int> dp(n,1) , hash(n);
        int lastIndex = 0;
        int maxi = 1;
        
        for(int ind = 0 ; ind < nums.size() ; ind++){
                        hash[ind] = ind;
            for(int prev_ind = 0 ; prev_ind < ind ; prev_ind++){
                
                if(nums[ind]%nums[prev_ind] == 0 && dp[ind] < dp[prev_ind]+1){
                       dp[ind] =  dp[prev_ind]+1;
                        hash[ind] = prev_ind;
                }
                
                if(dp[ind] > maxi){
                    maxi = dp[ind];
                    lastIndex = ind;
                }
                
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(lastIndex != hash[lastIndex]){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};