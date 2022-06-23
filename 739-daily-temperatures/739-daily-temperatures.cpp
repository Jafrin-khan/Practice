class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        int n = nums.size();
        
        stack<pair<int,int>> st;
        vector<int> ans(n,1);
        
        for(int i = 0 ; i < n ; i++){
            
            if(st.empty()){
                st.push({nums[i],i});
            }
            
            else if(st.top().first < nums[i]){
                
                while(!st.empty() && st.top().first < nums[i]){
                    auto front = st.top();
                    int idx = front.second;
                    ans[idx] = i - idx;
                    st.pop();
                }
                
                st.push({nums[i],i});
            }
            
            else{
                st.push({nums[i],i});
            }
        }
        
        while(!st.empty()){
            int idx = st.top().second;
            ans[idx] = 0;
            st.pop();
        }
        
        return ans;
    }
};