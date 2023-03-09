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

/*
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
*/
    
//Tabulation
/*
Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M’. The stack space will be eliminated.
*/
    
    int f(int i , int j,  int n , int m ,vector<vector<int>>& grid,vector<vector<int>>& dp){
        for(int j = 0 ; j < m ; j++) dp[n-1][j] = grid[n-1][j];
        
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                
                int l = 1e9,d = 1e9,r = 1e9;
                if(j > 0) l = dp[i+1][j-1];
                d = dp[i+1][j];
                if(j < m-1) r = dp[i+1][j+1];
                dp[i][j] = grid[i][j] + min({l,r,d});
            }
        }
        
        return dp[i][j];
            
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m,0));
        int sum = 1e9;
        for(int i = 0 ; i < m ; i++){
            sum = min(sum , f(0,i,n,m,grid,dp));
        }
        return sum;
    } 
    
    
};