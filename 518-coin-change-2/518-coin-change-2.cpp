class Solution {
public:

    int change(int amt, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amt + 1 , 0));
        
        for(int i = 0 ; i <= amt ; i++){
            if(i%coins[0] == 0){
                dp[0][i] =  1;
            }
            else{
                dp[0][i] = 0;
            }
            
        }
        
        
        for(int ind = 1 ; ind < n ; ind++){
            
            for(int i = 0 ; i <= amt ; i++){
                
                  
                    int notTake = dp[ind -1][i];
                    int take = 0;
                    if(i >= coins[ind]){
                        take = dp[ind][i - coins[ind]];
                    }

                    dp[ind][i] = take + notTake;
            }
        }
        
        return dp[n-1][amt];
    }
};