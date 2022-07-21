class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char , int>> st;
        
        for(int i = 0 ; i < s.size() ; i++){

            if(!st.empty() && s[i] == st.top().first){
                
                if(st.top().second == k-1){
                    st.pop();
                }
                
                else{
                    st.top().second++;
                }
            }
            
            else{
                st.push({s[i] , 1});
            }   
        }
        
        string ans = "";
        
        while(!st.empty()){
            int i = st.top().second;
            
            while(i--){
                ans += st.top().first;
            }
            
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};