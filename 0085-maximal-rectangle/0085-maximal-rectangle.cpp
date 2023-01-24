class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i = 0 ; i <= n ; i++){
            while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
                int h = heights[st.top()];
                st.pop();
                int width;
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
          vector<int> heights(n,0);
        int ans = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0; //rememebr this else statement...very imp
            }
             ans = max(ans , largestRectangleArea(heights));
        }
        
        return ans;
    }
};