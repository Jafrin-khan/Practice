string countAndSay(int n) {
if(n == 1){
return "1";
}
if(n == 2){
return "11";
}
string s = "11";
//this is for nth number its not iterating anything just cases after base cases are there that is what is n = 3 , n=4 etc
for(int i = 3 ; i <= n ; i++){
string t = "";
s+='$';
int cnt = 1;
//this is iterating through the number n
for(int j = 1 ; j < s.length() ; j++){
if(s[j-1] != s[j]){
t = t + to_string(cnt);
t = t+ s[j-1];
cnt = 1;
}
else{
cnt++;
}
}
s = t;
}
return s;
}