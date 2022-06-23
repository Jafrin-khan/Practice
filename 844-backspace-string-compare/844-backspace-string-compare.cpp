class Solution {
public:
    bool backspaceCompare(string s1, string s2) {
        
        stack<int> st;
        
        for(int i = 0 ; i < s1.size() ; i++){
            
            if(s1[i] == '#'){
                
                if(!st.empty()){
                st.pop();
                }
                
                else{
                    continue;
                }
            }
            
            else{
                st.push(s1[i]);
            }
        }
        
        string toCompare = "";
        while(!st.empty()){
            toCompare += st.top();
            st.pop();
        }
        
        for(int i = 0 ; i < s2.size() ; i++){
            
             if(s2[i] == '#'){
                
                if(!st.empty()){
                st.pop();
                }
                
                else{
                    continue;
                }
            }
            
            else{
                st.push(s2[i]);
            }
        }
        int k = 0;
        while(!st.empty()){
            if(toCompare[k++] != st.top()){
                return false;
            }
            st.pop();
        }
        
        if(k != toCompare.size()){
            return false;
        }
        
        return true;
    }
};