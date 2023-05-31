class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        
        stack<int> st;
        int n = histo.size();
        
        int ans = 0;
        
        for(int i = 0 ; i <= n ; i++){
            while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
                int h = histo[st.top()] ; st.pop();
                int width;
                if(!st.empty()) width = i - st.top() - 1;
                else width = i;
                ans = max(ans , width*h);
            }
            st.push(i);
        }
        
        return ans;
        
    }
};