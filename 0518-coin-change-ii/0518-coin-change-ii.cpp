class Solution {
public:
/*
   //Recursive
    //TC = O(2^N)
    //SC = O(N)
    int f(int ind , int amt ,  vector<int>& coins){
        if(ind == 0){
            if(amt%coins[0] == 0) return 1;
            else return 0;
        }
        
        int take = 0;
        if(amt >= coins[ind]) take = f(ind,amt - coins[ind] , coins);
        int notTake = f(ind-1 , amt , coins);
        
        return take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        return f(n-1 , amount , coins);
    }
    
*/
    
/*
    //Memoised
    //TC = O(N*T)
    //SC = O(N*T)+O(N)
    
//Time Complexity: O(N*T)
//Reason: There are N*W states therefore at max ‘N*T’ new problems will be solved.
//Space Complexity: O(N*T) + O(N)
//Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
    
    int f(int ind , int amt ,  vector<int>& coins , vector<vector<int>>& dp){
        if(ind == 0){
            if(amt%coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int take = 0;
        if(amt >= coins[ind]) take = f(ind,amt - coins[ind] , coins , dp);
        int notTake = f(ind-1 , amt , coins , dp);
        
        return dp[ind][amt] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1,-1));
        return f(n-1 , amount , coins , dp);
    }
*/
    
     //Tabulated
    //TC = O(N*T)
    //SC = O(N*T)

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1,0));
        
        for(int amt = 0 ; amt <= amount ; amt++){
            if(amt%coins[0] == 0) dp[0][amt] = 1;
        }
        
        for(int ind = 1 ;  ind < n ; ind++){
            for(int amt = 0 ; amt <= amount ; amt++){
                int take = 0;
                if(amt >= coins[ind]) take = dp[ind][amt - coins[ind]];
                int notTake = dp[ind-1][amt];

                dp[ind][amt] = take + notTake;
            }
        }
        
        return dp[n-1][amount];
    }
    
};