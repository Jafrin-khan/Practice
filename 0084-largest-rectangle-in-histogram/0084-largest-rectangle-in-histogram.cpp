class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        
        int n = histo.size();
        stack<int> st;
        
        int ans = 0;
        
        for(int i = 0 ; i <= n ; i++){
            while( !st.empty() && (i == n || histo[st.top()] >= histo[i])){
                
                int height = histo[st.top()];
                st.pop();
                
                int width;
                if(st.empty()) width = i;
                else width = i - st.top()-1;
                
                ans = max(ans , height*width);
            }
            st.push(i);
        }
        
        return ans;
    }
};