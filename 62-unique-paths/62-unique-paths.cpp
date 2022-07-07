class Solution {
public:
    
    int f(int i , int j ,int m,int n, vector<vector<int>>& dp){
        
        if(i == 0 && j == 0){
            return 1;
        }
        
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = f(i-1,j,m,n , dp);
        int down = f(i,j-1,m,n , dp);
        
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1 , n-1 , m , n , dp);
        
    }
};