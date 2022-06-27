class Solution {
public:
    string reverseWords(string s) {
        
        int i = 0;
        int n = s.length();
        
        stack<string> st;
        
        for(i = 0 ; i < n ; i ++){
            string toPut = "";
            
            while(i < n && s[i] != ' '){
                
                toPut+=s[i];
                i++;
            }
            
            if(toPut.size()){
                st.push(toPut);
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
            
            if(st.size() == 0){
                break;
            }
            ans+= " "; 
            
        }
        
        return ans;
        
    }
};