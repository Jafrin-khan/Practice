string removeDuplicates(string s, int k) {
stack<pair<char,int>>st;
int n=s.size();
for(int i=0;i<n;i++)
{
if(st.empty())
{
st.push({s[i],1});
continue;
}
if(st.top().first==s[i])
{
if(st.top().second==k-1)st.pop();
else
{
st.top().second++;
}
}
else
{
st.push({s[i],1});
}
}
string ans="";
while(!st.empty())
{
for(int i=0;i<st.top().second;i++)
{
ans+=st.top().first;
}
st.pop();
}
reverse(ans.begin(),ans.end());
return ans;
}