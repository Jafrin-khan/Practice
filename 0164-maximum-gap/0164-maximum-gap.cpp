class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) return 0;
        
        set<int> st;

        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        
        int prev = -1;
        int maxDiff = 0;
        
        for(auto it : st){
            if(prev == -1) prev = it;
            else{
                maxDiff = max(maxDiff , it - prev);
                prev = it;
            }
        }
        
        return maxDiff;
        
    }
};