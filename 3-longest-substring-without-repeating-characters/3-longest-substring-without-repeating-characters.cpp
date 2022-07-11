class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> st;
        
        int i = 0 , j = 0 , maxLength = 0 , n = s.size()-1;
        while(i < s.size()){
            
            if(st.find(s[i]) == st.end()){
                st.insert(s[i++]);
                maxLength = max(maxLength , int(st.size()));
            }
            
            else{
                st.erase(s[j++]);
            }
        }
        
        return maxLength;
    }
};