class Solution {
public:
    
    int f(int ind , int buy ,int cnt, vector<int>& prices , vector<vector<vector<int>>>& dp){
        
        if(ind == prices.size() || cnt == 2) return 0;
        
        if(dp[ind][buy][cnt] != -1) return dp[ind][buy][cnt];
        
        int profit = 0;
        if(buy){
            profit += max(-prices[ind] + f(ind+1 , 0 , cnt , prices , dp) , 0 + f(ind+1 , 1 , cnt , prices , dp));
        }
        
        else profit += max(prices[ind] + f(ind+1 , 1 , cnt+1 , prices , dp) , 0 + f(ind+1 , 0 , cnt , prices , dp));
        
        return dp[ind][buy][cnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(2 , -1)));
        int cnt = 0;
        return f(0 , 1 ,cnt , prices , dp);
    }
};