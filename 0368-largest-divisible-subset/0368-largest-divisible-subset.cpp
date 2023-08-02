class Solution {
public:
    
    /*
Time Complexity: O(N*N)

Reason: There are two nested loops.

Space Complexity: O(N)

Reason: We are only using two rows of size n.
    */
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());/////////////////////////
        int n = nums.size();
        
        vector<int> dp(n , 1);
        vector<int> hash(n);
        
         int lastIndex = 0;
        int lis = 1;//sirf comparison k lie.. koi kaam ni iska aage..hum use krre taaki hmein lastIndex mil ske
        
       
        for(int ind = 0 ; ind < n ; ind++){
            hash[ind] = ind;
            for(int prev = 0 ; prev <= ind-1 ; prev++){
                if((nums[ind]%nums[prev] == 0) && dp[ind] < dp[prev]+1){
                    dp[ind] = dp[prev]+1;
                    hash[ind] = prev;
                }
            }
            
            if(dp[ind] > lis){
                lis = dp[ind];
                lastIndex = ind;
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