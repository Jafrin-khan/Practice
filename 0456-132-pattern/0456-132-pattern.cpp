class Solution {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        stack<pair<int , int>> st; //<num , minLeft>.....<3,1>
        
        int currMin = nums[0];
        
        for(int i = 1 ; i < n ; i++){//hum 2nd no of dhundre hai looping krke
            
            while(!st.empty() && st.top().first <= nums[i]){//yahan pattern ke 3 se compare krre
                st.pop();
            }
            
            if(!st.empty() && st.top().second < nums[i]){//yahan pattern ke 1 se compare krre
                return true;
            }
            
            st.push({nums[i] , currMin});
            currMin = min(nums[i] , currMin);
        }
      return false;
    }
};