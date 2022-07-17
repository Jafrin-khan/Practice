class Solution {
public:
int numDecodings(string s) {
int ans=0;
ans = recur(s,0);
return ans;
}
int recur(string s, int pos){
if(pos==s.size())return 1;
if(s[pos]=='0')return 0;
if(pos==s.size()-1)return 1;
string b = s.substr(pos,2);
int way1 = recur(s,pos+1);
int way2=0;
if(stoi(b)<=26&&stoi(b)>0){
way2 = recur(s,pos+2);
}
return way1+way2;
}
};