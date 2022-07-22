class Solution {
public:
    string removeKdigits(string s, int k) {
        
        stack<char> st;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            while(!st.empty() && st.top() > s[i] && k){
                st.pop();
                k--;
            }
            
            if(st.empty() && s[i] == '0'){
                continue;
            }
            
            st.push(s[i]);
        }
        
        
        while(!st.empty() && k--){
            st.pop();
        }
        string ans = "";
        if(st.empty()){
            ans += "0";
            return ans;
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
        
    }
};