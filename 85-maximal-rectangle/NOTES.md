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
int maximalRectangle(vector<vector<char>>& matrix) {
int ans = 0;
vector<int> heights(matrix[0].size() , 0);
for(int i = 0 ; i < matrix.size() ; i++){
for(int j = 0 ; j < matrix[0].size() ; j++){
if(matrix[i][j] == '1'){
heights[j]++;
}
else{
heights[j] = 0;
}
}
int area =  largestRectangleArea(heights);
ans = max(ans , area);
}
return ans;
}