pair<int, int> count(string str){
int one = 0, zero = 0;
for (auto s: str){
if (s == '1')
one++;
else
zero++;
}
return {zero, one};
}
int f(int index, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& dp){
if (index == 0){
auto total = count(strs[0]);
if (total.first <= m && total.second <= n)
return 1;
else
return 0;
}
if (dp[index][m][n] != -1)
return dp[index][m][n];
int notTake = 0 + f(index - 1, m, n, strs, dp);
int take = 0;
auto total = count(strs[index]);
if (total.first <= m && total.second <= n)
take = 1 + f(index - 1, m - total.first, n - total.second, strs, dp);
return dp[index][m][n] = max(take, notTake);
}
int findMaxForm(vector<string>& strs, int m, int n) {
int length = strs.size();
vector<vector<vector<int>>> dp(length, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
return f(length - 1, m, n, strs, dp);
}
};