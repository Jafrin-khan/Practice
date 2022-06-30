class Solution {
public:
    
    int f(int ind , vector<int>& arr, int k , vector<int> &dp){
        
        if(ind >= arr.size()){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int maxi = INT_MIN;
        int len = 0;
        int maxAns = 0;
        int n = arr.size();
        
        for(int i = ind ; i < min(n , ind+k) ; i++){
            len++;
            maxi = max(maxi , arr[i]);
            int sum = maxi*len + f(i+1 , arr , k , dp);
            
            maxAns = max(maxAns , sum);
        }
        
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0 , arr , k , dp);
        
    }
};