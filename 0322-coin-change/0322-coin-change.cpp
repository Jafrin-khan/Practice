class Solution {
public:
/*Recursive...TC =     SC = 

    
 /*
 //Memoised
//Time Complexity: O(N*T)

//Reason: There are N*T states therefore at max ‘N*T’ new problems will be solved.

//Space Complexity: O(N*T) + O(N)

//Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
    
    
    int f(int ind , int amt , vector<int>& coins , vector<vector<int>>& dp){
        
        //remeber this base condition...kyu aai ye sb
        if(ind == 0){
            if(amt%coins[0] == 0) return amt/coins[0];
            return 1e9;
        }
        
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int take = 1e9;//remember 1e9 return krwana h coz min hai
        if(coins[ind] <= amt) take = 1 + f(ind , amt - coins[ind] , coins,dp);//el coin ko baar baar use kr skte hence not decreasing ind
        int notTake = 0 + f(ind-1 , amt , coins,dp);
        
        return dp[ind][amt] = min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));//amlount+1
        
        int ans = f(n-1 , amount , coins , dp);
        
        if(ans == 1e9) return -1;
        
        return ans;
        
    }*/
    
    //Tabulation
//Time Complexity: O(N*T)

//Reason: There are two nested loops

//Space Complexity: O(N*T)

//Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.
      int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , 0));//amlount+1
        
        for(int amt = 0 ; amt <= amount ; amt++){
             if(amt%coins[0] == 0) dp[0][amt] = amt/coins[0];
             else dp[0][amt] = 1e9;
        }
        
        for(int ind = 1 ; ind < n ; ind++){
            for(int amt = 0 ; amt <= amount ; amt++){
                int take = 1e9;
                if(coins[ind] <= amt) take = 1 + dp[ind][amt - coins[ind]];
                int notTake = 0 + dp[ind-1][amt];

                dp[ind][amt] = min(take,notTake);
            }
        }
        
        
        int ans = dp[n-1][amount];
        if(ans == 1e9) return -1;
        
        return ans;
        
    }
    
};