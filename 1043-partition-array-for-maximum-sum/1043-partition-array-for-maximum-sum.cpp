class Solution {
public:
    
    int f(int ind , vector<int>& arr , int k ,  vector<int>& dp){
        
        if(ind == arr.size()){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        int len = 0;
        int ans = INT_MIN;
        int maxi = INT_MIN;
        int n = arr.size();
        for(int j = ind ; j < min(n , ind + k) ; j++){

            maxi = max(maxi , arr[j]);
            len++;
            int sum = len*maxi  + f(j+1  , arr , k , dp);
            ans = max(ans , sum);
    
        }
        
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int> dp(arr.size() , -1);
        return f(0 , arr , k , dp);
    }
};