class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        stack<pair<int,int>> st;
        int ans = INT_MIN;
        
        for(int i = 0 ; i <= h.size() ; i++){
            
            while(!st.empty() && ( i == h.size() || st.top().first > h[i])){
                
                int height = st.top().first;
                st.pop();
                int width;
                
                if(st.empty()){
                    width = i;
                }
                
                else{
                    width = i - st.top().second - 1;
                }
                
                ans = max(ans , height*width);
                
            }
            
            if(i == h.size()){
                st.push({INT_MIN , i});
            }
            
            else{
            st.push({h[i] , i});
            }
        }
        
        return ans;
        
    }
};