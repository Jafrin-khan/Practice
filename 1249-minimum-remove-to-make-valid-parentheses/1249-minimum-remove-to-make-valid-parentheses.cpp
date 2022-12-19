class Solution {
public:
    
    /*
    TC = O(N) + O(N) ~ O(N)
    SC = O(N) + O(N) ~ O(N)
    */
    string minRemoveToMakeValid(string s) {
        
        unordered_map<int,bool> inValid;
        stack<pair<char , int>> st;
        
        string ans = "";
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                st.push({s[i] , i});
            }
            
            else if(s[i] == ')'){
                
                if(st.empty()){
                    inValid[i] = true;
                }
                
                else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            inValid[st.top().second] = true;
            st.pop();
        }
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(inValid.find(i) != inValid.end()){
                continue;
            }
            
            ans+=s[i];
        }
        
        
        return ans;
        
        
        
    }
};