class Solution {
public:  
    /*
    //Recursion
    //TC = O(3^N)..check
    //SC = O(N)
    
    int f(int ind , int buy , int t , int n , vector<int>& prices){
        
        if(ind == n) return 0;
        if(t == 2) return 0;
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1 , 0 , t , n , prices) , 0 + f(ind+1 , 1 , t , n , prices));
        }
        else profit = max(prices[ind] + f(ind+1 , 1 , t+1 , n , prices) , 0 + f(ind+1 , 0 , t , n , prices));//jab sell krte hai stocks tb transaction complete hoga
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        return f(0 , 1 , 0 , n , prices);
    }
    */
    /*
    
    //Memoised
    //TC = O(2*3*N)
    //SC = O(2*3*N) + O(N)
    
    int f(int ind , int buy , int t , int n , vector<int>& prices , vector<vector<vector<int>>>& dp){
        
        if(ind == n) return 0;
        if(t == 2) return 0;
        
        if(dp[ind][buy][t] != -1) return dp[ind][buy][t];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1 , 0 , t , n , prices , dp) , 0 + f(ind+1 , 1 , t , n , prices , dp));
        }
        else profit = max(prices[ind] + f(ind+1 , 1 , t+1 , n , prices , dp) , 0 + f(ind+1 , 0 , t , n , prices , dp));//jab sell krte hai stocks tb transaction complete hoga
        
        return dp[ind][buy][t] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (2 , vector<int>(3,-1)));//buy --> 0 or 1     transactions --> two ---> 0 , 1 , 2
        
        return f(0 , 1 , 0 , n , prices , dp);
    }
    */
     //Tabulation
    //TC = O(2*3*N)
    //SC = O(2*3*N) 

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int>(3,0)));//buy --> 0 or 1     transactions --> two ---> 0 , 1 , 2
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int t = 1 ; t >= 0 ; t--){
                        int profit = 0;
                        if(buy){
                            profit = max(-prices[ind] + dp[ind+1][0][t] , 0 + dp[ind+1][1][t]);
                        }
                        else profit = max(prices[ind] + dp[ind+1][1][t+1] , 0 + dp[ind+1][0][t]);//jab sell krte hai stocks tb transaction complete hoga

                        dp[ind][buy][t] = profit;
                                }
            }
        }
        
        return dp[0][1][0];
    }
};