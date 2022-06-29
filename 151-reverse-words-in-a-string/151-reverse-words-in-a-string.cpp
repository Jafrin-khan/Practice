class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            string temp = "";
            
            while(i < s.size() && s[i] != ' '){
                temp+=s[i++];
            }
            
            if(temp.size() != 0){
                st.push(temp);
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(st.size() == 0){
                break;
            }
            
            else{
                ans += " ";
            }
        }
        
        return ans;
        
        
    }
};