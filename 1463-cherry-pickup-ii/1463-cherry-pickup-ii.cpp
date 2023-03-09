class Solution {
public:
    /*
    //Recursion
    //TC :
    //SC :
    int f(int i , int j1 , int j2 , int n , int m , vector<vector<int>>& grid){
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e9;
        if(i == n-1){
            if(j1 == j2) return grid[n-1][j1];
            else return grid[n-1][j1] + grid[n-1][j2];
        }
        
        int maxi = -1e9;
        for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
            for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                int value = 0;
                if(j1 == j2)  value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1 , j1+dj1 , j2+dj2 , n , m , grid);
                maxi = max(maxi,value);
            }
        }    
        
        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return f(0,0,m-1,n,m,grid);
        
    }*/
    
    //Memoization
    /*
Time Complexity: O(N*M*M) * 9

Reason: At max, there will be N*M*M calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times.

Space Complexity: O(N) + O(N*M*M)

Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M*M’.
    */
  
    //Tabulation
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(m,0)));
        
        for(int j1 = 0 ; j1 < m ; j1++){
            for(int j2 = 0 ; j2 < m ; j2++){
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j1 = m-1 ; j1 >= 0 ; j1--){
                for(int j2 = 0 ; j2 < m ; j2++){
                    int maxi = -1e9;
                    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
                        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                            int value = 0;
                            if(j1 == j2)  value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if((j1+dj1 < 0 || j1+dj1 >= m) || (j2+dj2 < 0 || j2+dj2 >= m)){
                                 value += -1e9;
                            }
                            else  value += dp[i+1][j1+dj1][j2+dj2];
                            maxi = max(maxi,value);
                        }
                    }    
        
                   dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
        
    }
};