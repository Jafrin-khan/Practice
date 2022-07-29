class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    
       
        int n = nums.size();
        
        if(n == 0){
            return {};
        }
        
        if(n == 1){
            return {nums[0]};
        }
         
        sort(nums.begin() , nums.end());
        vector<int> dp(n , 1);
        vector<int> hash(n);
        
        int lastIndex;
        int maxi = 1;
        
        for(int ind = 0 ; ind < n ; ind++){
              hash[ind] = ind;
            for(int prev = 0 ; prev < ind ; prev++){
               
              if(nums[ind]%nums[prev] == 0 && dp[ind] < dp[prev] + 1){
                  dp[ind] = dp[prev] + 1;
                  hash[ind] = prev;
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
        
        
        
        return ans;
        
    }
};