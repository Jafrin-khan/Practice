class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = "11";
        n -= 2;
         
        while(n--){
            
            string str = "";
            int i = 0;
            while(i < s.size()){
                int cnt = 1 ; char ch = s[i];
                while(i < s.size()-1 && s[i] == s[i+1]) {cnt++ ; i++;}
                str = str + to_string(cnt) + s[i];
                i++;
            }
            s = str;
            cout<<s<<endl;
        }
        return s;
    }
};