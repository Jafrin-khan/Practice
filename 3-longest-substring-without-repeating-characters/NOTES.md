set<char> st;
int i = 0;
int j = 0;
int maxLength = 0;
while(i < s.length()){
if(st.find(s[i]) == st.end()){
st.insert(s[i]);
maxLength = max(maxLength,int(st.size()));
i++;
}
else{
st.erase(s[j++]);
}
}
return maxLength;