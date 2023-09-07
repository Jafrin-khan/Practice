int repeatedStringMatch(string a, string b) {
string copy = a;
int cnt = 1;
while(a.size() < b.size()){
a += copy;
cnt++;
}
if(a.find(b) != -1) return cnt;
a += copy;
cnt++;
if(a.find(b) != -1) return cnt;
return -1;
}