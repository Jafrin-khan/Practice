class Solution {
public:
    
     int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size(); 
        stack<int> st;
        int ans = 0;
        
        for(int i = 0 ; i <= n ; i++){
            
            while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                   width = i;
                }
                
                else{
                    width = i - st.top()-1;
                }
                ans = max(ans , height*width);
                  
            }
            
            st.push(i);    
        }
        
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
           vector<int> heights(matrix[0].size() , 0);
           
           int ans = 0;
        
           for(int i = 0 ; i < matrix.size() ; i++){
               for(int j = 0 ; j < matrix[0].size() ; j++){
                   
                   if(matrix[i][j] == '1'){
                       heights[j]++;
                   }
                   
                   else{
                       heights[j] = 0;
                   }
               }
               int area = largestRectangleArea(heights);
               ans = max(ans , area );
           }
        
        return ans;
    }
};