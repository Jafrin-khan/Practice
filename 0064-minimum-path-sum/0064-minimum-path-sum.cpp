class Solution {
public:
    
    /*TC : O(m*n)
    SC :O((M-1)+(N-1)) + O(N*M)

Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.
    */
    
    int f(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
        
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        
        if(i < 0 || j < 0){
            return 1e9;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
       
        int left = grid[i][j] + f(i , j-1 , grid , dp);
        int up = grid[i][j] + f(i-1 , j , grid , dp);
        
        return dp[i][j] = min(left , up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n , -1));
        
        return f(m-1 , n-1 , grid , dp);
        
    }
};