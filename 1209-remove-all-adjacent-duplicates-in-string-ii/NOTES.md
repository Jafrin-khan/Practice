stack<pair<char,int>> st;
for(int i = 0 ; i < s.length() ; i++){
if(st.empty()){
st.push({s[i],1});
continue;
}
if(st.top().first == s[i]){
if(st.top().second == k-1){
st.pop();
}
else{
st.top().second++;
}
}
else{
st.push({s[i],1});
}
}
string ans = "";
while(!st.empty()){
int i = 0;
while(i < st.top().second){
ans += st.top().first;
i++;
}
st.pop();
}
reverse(ans.begin(),ans.end());
return ans;
}