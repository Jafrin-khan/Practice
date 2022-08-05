string simplifyPath(string s) {
stack<string> st;
for(int i = 0 ; i < s.size() ; i++){
if(s[i] == '/'){
continue;
}
string temp = "";
while(i < s.size() && s[i] != '/'){
temp += s[i];
i++;
}
if(temp == "." || temp == ""){
continue;
}
if(temp == ".."){
if(!st.empty()){
st.pop();
}
}