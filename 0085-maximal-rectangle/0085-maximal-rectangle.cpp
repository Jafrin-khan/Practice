class Solution {
public:
    /*
    TC = O(N*(M+N))
    SC = O(N)
    */
    int largestRectangleHisto(vector<int>& histo) {
        
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> histo(m , 0);
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1') histo[j]++;
                else histo[j] = 0;
            }
            
            ans = max(ans , largestRectangleHisto(histo));
        }
        
        return ans;
    }
};