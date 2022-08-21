class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int price = INT_MAX;
        int profit = INT_MIN;
        
        for(int i = 1 ; i < prices.size() ; i++){
            
            price = min(prices[i-1] , price);
            profit = max(profit , prices[i] - price);
        }
        if(profit < 0){
            return 0;
        }
        return profit;
        
    }
};