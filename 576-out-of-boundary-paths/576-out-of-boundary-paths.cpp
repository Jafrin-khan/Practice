
class Solution {
public:
     int dp[51][51][51];
    long long mod = 1e9 + 7;
    int f(int i , int j , int m , int n , int maxMove){
       
        
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 1;
        }
        
         
        if(maxMove <= 0){
            return 0;
        }
        
        if(dp[i][j][maxMove] != -1){
            return dp[i][j][maxMove];
        }
        
        int down = (f(i+1 , j , m , n , maxMove-1 ));
        int right =  (f(i , j+1 , m , n , maxMove-1 ));
        int up =  (f(i-1 , j , m , n , maxMove-1 ));
        int left =  (f(i , j-1 , m , n , maxMove-1 ));
        
        int total = (down%mod + right%mod + up%mod + left%mod)%mod;
                  
        return dp[i][j][maxMove] = total;     
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
       memset(dp , -1 , sizeof(dp));

        return f(startRow , startColumn , m , n , maxMove);
    }
};