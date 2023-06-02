class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
        int n = s.size();
        
        int i = 0;
        while(i < n){
            
            string temp = "";
            while(i < n && s[i] != ' ') temp += s[i++];
            if(temp.size() != 0) ans = " " + temp + ans;
            
            i++;
        }
        
        return ans.substr(1);
    }
};