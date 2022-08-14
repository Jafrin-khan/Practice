class Solution {
public:
    
    string f(string s){
        
        int i = 0;
        string ans = "";
        
        while(i < s.size()){
            
            int cnt = 0;
            char ch = s[i];
            while(i < s.size() && s[i] == ch){
                cnt++;
                i++;
            }
            
            ans += to_string(cnt) + ch;
        }
        
        return ans;
    }
    string countAndSay(int n) {
        
        string ans = "1";
        for(int i = 2 ; i <= n ; i++){
           ans = f(ans);
        }
        
        return ans;
        
    }
};