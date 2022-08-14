class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        int n = s.size();
        
        int i = 0;
        
        while(i < n){
            
            string temp = "";
            
            while(i < n && s[i] !=' '){
                temp += s[i++];
            }
            
            if(temp.size() != 0){
                st.push(temp);
            }
            
            i++;
        }
        
        string ans = "";
        
        ans += st.top();
        st.pop();
        while(!st.empty()){
            ans += ' ' + st.top();
            st.pop();
        }
        
        return ans;
        
    }
};