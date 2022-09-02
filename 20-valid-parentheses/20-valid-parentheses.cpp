class Solution {
public:
    bool isValid(string s) {
        
         stack<char> st;
        bool flag = false;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            
            else{
                
                if(st.empty()){
                    return false;
                }
                
                char front = st.top();
           
                
                if( (s[i] == '}' && front == '{') || (s[i] == ']' && front == '[') || (s[i] == ')' && front == '(')  ){
                    st.pop();
                }
                
                else{
                    return false;
                }
              
            }
            
        }
        
        if(!st.empty()){
            return false;
        }
        
        return true;;
        
    }
};