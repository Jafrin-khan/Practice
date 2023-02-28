class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string ans = "11";
        
        for(int num = 3 ; num <= n ; num++){
            int i = 0;
            string toReplace = "";
            while(i < ans.size()){
                int cnt = 0;
                char ch = ans[i];
                while(i < ans.size() && ans[i] == ch){
                    cnt++;i++;
                }
              
                toReplace += to_string(cnt);
                toReplace += ch;
            }
            ans = toReplace;
        }
        
        return ans;
    }
};