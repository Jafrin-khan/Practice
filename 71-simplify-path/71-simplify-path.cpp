class Solution {
public:
    string simplifyPath(string path) {
        
        int i = 0;
        int n = path.size();
        
        stack<string> st;
        
        while(i < n){
            
            string temp = "";
            
            while(i < n && path[i] == '/'){
                i++;
            }
            
            while(i < n && path[i] != '/'){
                temp += path[i++];
            }
            
            if(temp == "." || temp == ""){
                continue;
            }
            
            if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
                
                continue;
            }
            
            st.push(temp);   
            
        }
        
        string ans = "";
        
        if(st.empty()){
            return "/";
        }
        
        while(!st.empty()){
            
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};