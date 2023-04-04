class Solution {
public:
    
    /*
    TC = O(N)...check from friends once though 90% sure its correct
    SC = O(N) + O(N) ~ O(N) 
    */
    string reverseParentheses(string s) {
    
        stack<char> st;
        queue<char> q;
        
        string ans = "";
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                st.push(s[i]);
            }
            
            else if(s[i] != ')' && !st.empty()){
                st.push(s[i]);
            }
            
            else if(s[i] != ')' && st.empty()){
                ans += s[i];
            }
         
            else{
                
                while(st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
        
                st.pop();
                
                if(st.empty()){
                    
                    while(!q.empty()){
                    ans += q.front();
                    q.pop();
                    }
                }
               
                else{
                    while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                    }
                }
                
                
            }
        }
        
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};