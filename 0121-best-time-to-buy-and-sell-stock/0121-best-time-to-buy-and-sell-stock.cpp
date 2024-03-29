class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;
        int mini = prices[0];
        
        for(int i = 0 ; i < n ; i++){
            mini = min(mini , prices[i]);
            profit = max(profit , prices[i] - mini);
        }
        
        return profit;
    }
};