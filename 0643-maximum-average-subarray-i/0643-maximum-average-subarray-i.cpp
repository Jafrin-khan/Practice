class Solution {
public:
    /*
    TC = O(K) + O(N-k)
    SC = O(1)
    */
    double findMaxAverage(vector<int>& nums, int k) {
        
        int p = k;
        int i = 0;
        double sum = 0;
        
        while(p--){
            sum += nums[i++];
        }
        
        double ans = sum/k;
        
        while(i < nums.size()){
            sum -= nums[i-k];
            sum += nums[i++];
            double avg= sum/k;
            ans = max(ans , avg);
        }
        return ans;
    }
};