class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int price = prices[0];
        for(int i = 0 ; i < prices.size() ; i++){
            price = min(prices[i] , price);
            maxProfit = max(maxProfit , prices[i] - price);
        }
        
        return maxProfit;
        
    }
};