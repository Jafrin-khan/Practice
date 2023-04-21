class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int price = prices[0];
        int maxProfit = 0;
        
        for(int i = 1 ; i < prices.size() ; i++){
            maxProfit = max(maxProfit , prices[i] - price);
            price = min(price , prices[i]);
        }
        
        return maxProfit;
        
    }
};