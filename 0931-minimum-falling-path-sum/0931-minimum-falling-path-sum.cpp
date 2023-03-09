class Solution {
public:
/*
 //Recursion
    
 //TC : 
 //SC : 
    
    int f(int i , int j,  int n , int m ,vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m) return 1e9;
        if(i == n-1) return grid[i][j];
        int l = f(i+1,j-1,n,m,grid);
        int d = f(i+1,j,n,m,grid);
        int r = f(i+1,j+1,n,m,grid);
        return grid[i][j] + min({l,d,r});
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 1e9;
        for(int i = 0 ; i < m ; i++){
            sum = min(sum , f(0,i,n,m,grid));
        }
        return sum;
    }
*/
    
//Memoization
// Time Complexity: O(N*N)

// Reason: At max, there will be M*N calls of recursion to solve a new problem,

// Space Complexity: O(N) + O(N*M)

// Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M’.
    
    int f(int i , int j,  int n , int m ,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= n || j >= m) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == n-1) return dp[i][j] = grid[i][j];
       
        int l = f(i+1,j-1,n,m,grid,dp);
        int d = f(i+1,j,n,m,grid,dp);
        int r = f(i+1,j+1,n,m,grid,dp);
        return dp[i][j] = grid[i][j] + min({l,d,r});
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        int sum = 1e9;
        for(int i = 0 ; i < m ; i++){
            sum = min(sum , f(0,i,n,m,grid,dp));
        }
        return sum;
    }
};