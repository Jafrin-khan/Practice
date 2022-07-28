class Solution {
public:
bool f(int i,int j,string &pattern,string &text,vector<vector<int>>&dp)
{
// Base Cases
if(i<0 && j<0) return true;
if(i<0 && j>=0) return false;
if(i>=0 && j<0) {
for(int k=0;k<=i;k++)
if(pattern[k]!='*') return false;
return true;
}
if(dp[i][j]!=-1) return dp[i][j];
if(pattern[i]==text[j] || pattern[i]=='?')
return dp[i][j] = f(i-1,j-1,pattern,text,dp);
else if(pattern[i] =='*')
return dp[i][j]=f(i-1,j,pattern,text,dp) || f(i,j-1,pattern,text,dp);
else return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
int m = p.length();
int n = s.length();
vector<vector<int>>dp(m,vector<int>(n,-1));
return f(m-1,n-1,p,s,dp);
}
};