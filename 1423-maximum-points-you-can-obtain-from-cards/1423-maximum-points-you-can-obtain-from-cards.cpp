class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int totSum = 0;
        
        for(int i = 0 ; i < n ; i++){
            totSum += nums[i];
        }
        
        int left = 0;
        int right = n - k;
        int window = 0;
        //assuming that the cards are taken from the back side of the deck;
        //window stores the items which are not taken
        for(int i = 0 ; i < right ; i++){
            window+=nums[i];
        }
        
        int maxCardSum = totSum - window;
        
        while(right < n){
            
            window -= nums[left++];
            window += nums[right++];
            
            maxCardSum = max(maxCardSum , totSum - window);
        }
        
        return maxCardSum;
    }
};