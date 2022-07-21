class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        
        int n = arr.size();
        stack<int> st;
        
        long long ans = 0;
        
        for(int i = 0 ; i <= n ; i++){
            
            while(!st.empty() && ((i == n) || arr[i] < arr[st.top()])){
                int y = st.top();
                st.pop();
                
                int x = st.empty()?-1 : st.top();
                ans += arr[y]*(long long)(y - x)*(i - y);
            }
            
            st.push(i);
            
        }
        
         ans = ans % (int)(1e9 + 7);
        return (int)ans;
        
        
    }
};