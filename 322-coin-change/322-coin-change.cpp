class Solution {
public:
    
 
    int coinChange(vector<int>& coins, int amt) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amt+1 , 0));
        
         for(int i = 0 ; i <= amt ; i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
             
            else{
                dp[0][i] = 1e9;
            }
        }
        
        for(int ind = 1 ; ind < n ; ind++){
            for(int j = 0 ; j <= amt ; j++){
                  
            int notTake = 0 + dp[ind - 1][j];
            int take = 1e9;

            if(coins[ind] <= j){
                take = 1 + dp[ind][j - coins[ind]]; 
            }

            dp[ind][j] = min(take , notTake);
            
            }
        }
        
        int ans =  dp[n - 1][amt];
        
        if(ans == 1e9){
            return -1;
        }
        
        return ans;
        
    }
};