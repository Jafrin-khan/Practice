class Solution {
public:
    string removeKdigits(string s, int k) {
        
        stack<char> st;
        int n = s.size();
        
        if(n == k){
            return "0";
        }
        
        for(int i = 0 ; i < n ; i++){
            while( !st.empty() && s[i]-'0' < st.top()-'0' && k){
                k--;
                st.pop();
                
            }
            
            if(st.empty() && s[i] -'0' == 0){
                continue;
            }
            
            st.push(s[i]);
        }
        
        while(k-- && !st.empty()){
            st.pop();
        }
        
        string ans = "";
        while(!st.empty()){
            cout<<st.top()<<endl;
            ans += st.top();
            st.pop();
        }
       
        
        if(ans.empty()){
            return "0";
        }
        
        reverse(ans.begin(),ans.end());
        int i = 0;
       
        return ans.substr(i,ans.size()+1);
         
    }
};