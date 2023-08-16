class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for (int i=1; i<=n; ++i){
            string s(to_string(i));
            set<char> c(s.begin(),s.end());
            if (c.count('3')||c.count('4')||c.count('7')) continue;
            if (c.count('2')||c.count('5')||c.count('6')||c.count('9')) ++cnt;
        }
        return cnt;
    }
};