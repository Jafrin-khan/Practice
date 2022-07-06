class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            string t = "";
            while(i < s.size() && s[i]!=' '){
                t += s[i++];
            }
            
            if(!t.empty()){
            st.push(t);
            }
        }
        
        string ans = "";
        if(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(!st.empty()){
            ans+= " " + st.top();
            st.pop();
        }
        
        return ans;
        
    }
};