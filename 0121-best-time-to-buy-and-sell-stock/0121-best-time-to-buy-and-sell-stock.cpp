class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxProfit = 0;
        int minVal = 1e9;
        
        for(int i = 0 ; i < n ; i++){
            minVal = min(minVal , prices[i]);
            maxProfit = max(maxProfit , prices[i] - minVal);
        }
        
        return maxProfit;
    }
};