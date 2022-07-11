class Solution {
public:
    
        bool f(int ind , int target , int n , vector<int>& arr ,  vector<vector<int>>& dp){
        
        if(target == 0){
            return true;
        }
        
        if(ind == 0){
            return false;
        }
        
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        bool notPick = f(ind - 1 , target , n , arr , dp);
        bool pick = false;
        if(arr[ind] <= target){
            pick = f(ind - 1 , target - arr[ind] , n , arr , dp);
        }
        
        return dp[ind][target] = pick || notPick;
    }
    bool canPartition(vector<int>& arr) {
        
         int target = 0;
         int n = arr.size();
        
        for(int i = 0 ; i < n ; i++){
            target += arr[i];
        }
        
        if(target%2 != 0){
            return 0;
        }
        
        target /= 2;
        
        vector<vector<int>> dp(n , vector<int>(target+1,-1));
        return f(n-1 , target , n , arr , dp);
    }
        
    
};