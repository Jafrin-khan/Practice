class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
  
    int evalRPN(vector<string>& s) {
        
        stack<int> st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == "+" || s[i] == "-" || s[i] == "/" || s[i] == "*"){
                int n1 = st.top();st.pop();
                int n2 = st.top();st.pop();
                if(s[i] == "+") st.push(n1 + n2);
                else if(s[i] == "-") st.push(n2 - n1);
                else if(s[i] == "*") st.push(n1 * n2);
                else if(s[i] == "/") st.push(int(n2 / n1));    
            }  
            else st.push(stoi(s[i]));
        }
        
        int ans = st.top();
        st.pop();
        
        return ans;
    }
};

                                             