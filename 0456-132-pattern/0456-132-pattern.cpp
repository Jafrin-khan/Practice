class Solution {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        stack<pair<int , int>> st; //<num , minLeft>
        
        int currMin = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            
            if(!st.empty() && st.top().second < nums[i]){
                return true;
            }
            
            st.push({nums[i] , currMin});
            currMin = min(currMin , nums[i]);
        }
      return false;
    }
};