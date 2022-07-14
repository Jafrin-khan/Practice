class Solution {
public:
static bool cmp(string &a , string &b){
return a.size() < b.size();
}
bool toCompare(string &s1 , string &s2){
int n = s1.size();
int m = s2.size();
if(n != m+1){
return false;
}
int p1 = 0;
int p2 = 0;
while(p1 < n){
if(s1[p1] == s2[p2]){
p1++;
p2++;
}
else{
p1++;
}
}
if(p1 == n && p2 == m){
return true;
}