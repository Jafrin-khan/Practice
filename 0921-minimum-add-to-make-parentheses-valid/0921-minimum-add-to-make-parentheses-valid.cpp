class Solution {
public:
    
    /*
    TC = O(N) + O(N)
    SC = O(N)
    */
    int minAddToMakeValid(string s) {
        
        stack<int> st;
        int cnt = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                st.push(s[i]);
            }
            
            else if(!st.empty()){
                st.pop();
            }
            
            else{
                cnt++;
            }
        }
        
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        
        return cnt;
        
    }
};