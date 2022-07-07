class Solution {
public:
    

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int> dp(arr.size()+1 , 0);
        
        for(int ind = arr.size()-1 ; ind >= 0 ; ind--){
                int len = 0;
                int ans = INT_MIN;
                int maxi = INT_MIN;
                int n = arr.size();
                for(int j = ind ; j < min(n , ind + k) ; j++){

                maxi = max(maxi , arr[j]);
                len++;
                int sum = len*maxi  + dp[j+1];
                ans = max(ans , sum);

        }
        
        dp[ind] = ans;
            
        }
        return dp[0];
    }
};