}
if(pattern[i] == text[j] || pattern[i] == '?'){
return dp[i][j] = f(i - 1 , j - 1 , text , pattern , dp);
}
else if(pattern[i] == '*'){
return dp[i][j] = f(i - 1 , j , text , pattern , dp) || f(i , j - 1 , text , pattern , dp);//////////////////   2nd condition //////////////////
}
else{
return dp[i][j] = false;
}
}
bool isMatch(string text, string pattern) {
int n = text.size();
int m = pattern.size();
vector<vector<int>> dp(m , vector<int>(n,-1));
return f(m-1 , n-1 , text , pattern , dp);
}