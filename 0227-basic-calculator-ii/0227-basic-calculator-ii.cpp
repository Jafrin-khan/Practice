class Solution {
public:
    
    int calculate(string s) {
        
        s+='+';
        stack<int> st;
        long long int curr = 0 , ans = 0;
        char sign = '+';
        for(int i = 0 ; i < s.size() ; i++){
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0');//keep forming number until we find operator
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                if(sign == '+') st.push(curr);
                else if(sign == '-')st.push(curr*-1);
                else if(sign == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top*curr);}
                else if(sign == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/curr);//Left to right chlta hai
                }
            curr = 0;
            sign = s[i];  //sign of next curr
        }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
            
        return ans;
    }
};