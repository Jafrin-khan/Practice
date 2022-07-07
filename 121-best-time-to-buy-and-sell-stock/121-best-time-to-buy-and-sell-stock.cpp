class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = INT_MIN;
        
        for(int i = 0 ; i < prices.size() ; i++){
            int price = min(price , prices[i]);
            maxProfit = max(maxProfit , prices[i] - price);
            
        }
        
        return maxProfit;
        
    }
};