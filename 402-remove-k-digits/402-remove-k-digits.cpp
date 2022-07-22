class Solution {
public:
    string removeKdigits(string s, int k) {
        
        stack<char> st;
        string ans = "";
        int i = 0;
        
        while(s[i] != '\0'){
            
             while(!st.empty() && st.top() > s[i] && k){
                 st.pop();
                 k--;
             }
            
            if(st.empty() && s[i] == '0'){
                i++;
                continue;
            }
            
            st.push(s[i++]);
        }
        
        while(k-- && !st.empty()){
            st.pop();
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        
        
        reverse(ans.begin() , ans.end());
        
        if(ans.empty()){
            ans += "0";
           
        }
        
        return ans;
        
    }
};