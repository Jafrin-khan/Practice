class Solution {
public:
    
    int f(int i , int j , int m , int n ,vector<vector<int>>& dp){
        
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        
        int right = f(i , j+1 , m , n , dp);
        int down = f(i+1 , j , m , n , dp);
        
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(0 , 0, m , n , dp);
        
    }
};