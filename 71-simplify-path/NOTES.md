string simplifyPath(string path) {
stack<string> st;
for(int i = 0 ; i < path.size() ; i++){
string temp = "";
while(i < path.size() && path[i] != '/'){
temp += path[i];
i++;
}
if(temp =="." || temp == ""){
continue;
}
if(temp == ".."){
if(!st.empty()){
st.pop();
}
}
else{
st.push(temp);
}
}
string ans = "";
if(st.empty()){
return "/";
}
while(!st.empty()){
ans  = '/' + st.top() + ans;
st.pop();
}
return ans;
}