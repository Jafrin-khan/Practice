class Solution {
public:
    
//     1
    
    
//                ~
//              ~ 1
        
//            3,3
        
//         3,2    2,3
        
//       2,2  3,1   1,2 2,2 -->Overlapping subproblems hence memoization
        
        
//     f(i , j){
        
//         if(i < 0 || j < 0) return 0;
//         if(i == 0 && j == 0) return 1;
        
//         int left = f(i , j - 1);
//         int up = f(i -1 , j);
        
//         return left + up;
//     }
    
     //see 03/07/2023  submission
    int f(int i , int j , vector<vector<int>>& dp){
        
        if(i < 0 || j < 0) return 0;
        
        if(i == 0 && j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = f(i , j-1 , dp);
        int up = f(i-1 , j , dp);
        
        return dp[i][j] = left + up;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(m-1 , n-1 , dp);
    }
};