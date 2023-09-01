class Solution {
public:
    
int mod = (int)(1e9 + 7);

int f(int target, vector<int> &arr,int idx,vector<vector<int>>& dp){
    
    if(idx == 0){
        if(target == 0 && arr[0] == 0){
            return 2;
        }
        
        if(target == 0 || target == arr[0]){
            return 1;
        }
        
        return 0;
    }
    
    if(dp[idx][target] != -1){
        return dp[idx][target];
    }
    int notPick = f(target,arr,idx-1,dp);
    int pick = 0;
    if(target >= arr[idx]){
        pick = f(target - arr[idx],arr,idx-1,dp);
    }
    
    return dp[idx][target] = (pick+notPick)%mod;
}


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int totSum = 0;
        for(int i = 0 ; i < n ; i++){
            totSum += nums[i];
        }
        
        int k = (totSum - target)/2;
        if((totSum - target)%2 || (totSum - target) < 0) return 0;
        
        vector<vector<int>> dp(n , vector<int>(k+1 , -1));
        
        return f(k , nums ,n-1, dp);
    }
};