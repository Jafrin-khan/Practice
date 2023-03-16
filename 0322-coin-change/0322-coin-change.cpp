class Solution {
public:
/*Recursive...TC =     SC = 

    
 /*Memoised
Time Complexity: O(N*T)

Reason: There are N*T states therefore at max ‘N*T’ new problems will be solved.

Space Complexity: O(N*T) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
    */
    
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
        
    }
};