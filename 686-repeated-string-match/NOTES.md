string ans = a;
int cnt = 1;
for(int i = 0 ; i < (b.size()/a.size()) + 2 ; i++){
int found = ans.find(b);
if(found != -1){
return cnt;
}
cnt++;
ans+=a;
}
return -1;