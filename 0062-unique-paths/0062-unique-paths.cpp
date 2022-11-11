class Solution {
public:
    
    /*
    TC : O(m*n)
    SC : O(m*n)     ..........Reason: We are using an external array of size ‘M*N’’.
    
    
    */

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m , vector<int>(n , 0));
        
        dp[0][0] = 1;
       
        for(int i = 0 ; i < m ; i++){
            
            for(int j = 0 ; j < n ; j++){
                
                if(i == 0 && j == 0){
                    continue;
                }
                
                 int left = 0;
                 int right = 0;
            
                
                if(j >= 1){
                left = dp[i][j-1];
                }
                
                if(i >= 1){
                right = dp[i-1][j];
                }

                dp[i][j] = left + right;
            }
        }
        return dp[m-1][n-1];
        
    }
};