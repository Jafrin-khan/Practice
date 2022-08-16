class Solution {
public:
    
    int f(int ind , int prod , vector<int>& nums , unordered_map<int,int> dp[]){
        
        if(ind < 0){
            return prod;
        }
        
        if(dp[ind].find(prod) != dp[ind].end()){
            return dp[ind][prod];
        }
        int notTaken = f(ind-1 , nums[ind] , nums , dp);
        int taken = f(ind - 1 , nums[ind]*prod , nums , dp);
        
        return dp[ind][prod] = max({prod , notTaken , taken});
    }
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> dp[n];
        return f(n-2 , nums[n-1] , nums , dp);
        
    }
};