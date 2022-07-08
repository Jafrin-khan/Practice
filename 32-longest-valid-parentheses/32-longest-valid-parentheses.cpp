class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int i = 0;
        int n = s.size();
        int ans = 0;
        
        while(i < n){
            
            if(s[i] == '('){
                st.push(i);
            }
            
            else{
                
                if(st.empty() || s[st.top()] == ')'){
                    st.push(i);
                }
                
                else{
                    st.pop();
                    int len;
                    if(st.empty()){
                        len = -1;
                    }
                    
                    else{
                        len = st.top();
                      }
                     ans = max(ans , i - len);
                }
            }
            
            i++;
        }
        
        return ans;
        
    }
};