class Solution {
public:
      int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(i==a.size()-1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=a[i+1][j]+f(i+1,j,a,dp);
        int r=a[i+1][j+1]+f(i+1,j+1,a,dp);
        return dp[i][j]=min(r,l);
    }
    int minimumTotal(vector<vector<int>>& a) {
        vector<vector<int>>dp(a.size(),vector<int>(a.size(),-1));
     int r=f(0,0,a,dp)+a[0][0];
        return r;
    }
};