class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
      stack<int> st;
        int rs , ls ,width , height;
        int ans = 0;
        
        for(int i = 0 ; i <= heights.size() ; i++){
            
            while(!st.empty() && (i == heights.size() || heights[st.top()] > heights[i])){
                int h = heights[st.top()];
                st.pop();
                
                if(st.empty()){
                    width = i;
                }
                
                else{
                    width = i - st.top() - 1;
                }
                
                ans = max(ans , h*width);
            }
            
            st.push(i);
        }
        
        return ans;
        
    }
};