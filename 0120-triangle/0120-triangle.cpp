class Solution {
public:
    /* See why this approach not working
    int f(int i , int j , vector<vector<int>>& triangle){
        if(j < 0 || i < 0) return 1e9;
        if(i == 0) return triangle[0][0];
        int l = f( i-1 , j , triangle);
        int r = f( i-1 , j-1 , triangle);
        
        return triangle[i][j] + min(l,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int ans = 1e9;
        for(int j = 0 ; j < triangle[n-1].size() ; j++){
            ans = min(ans , f(n-1 , j ,triangle));
        }
        
        return ans;
    }
    */
    
    /*
    //recursion
    //TC = 
    //SC = 
    int f(int i , int j , int n , vector<vector<int>>& triangle){
        if(i == n-1) return triangle[i][j];
        int l = f(i+1,j,n,triangle);
        int r = f(i+1,j+1,n,triangle);
        
        return triangle[i][j] + min(l,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        return f(0 , 0 , n , triangle);
    }
    */
    
    /*
    //memoization
// Time Complexity: O(N*N)

// Reason: At max, there will be (half of, due to triangle) N*N calls of recursion.

// Space Complexity: O(N) + O(N*N)

// Reason: We are using a recursion stack space: O((N), where N is the path length and an external DP Array of size ‘N*N’.
    int f(int i , int j , int n , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int l = f(i+1,j,n,triangle,dp);
        int r = f(i+1,j+1,n,triangle,dp);
        
        return dp[i][j] = triangle[i][j] + min(l,r);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        return f(0 , 0 , n , triangle , dp);
    }
    */
    
    //Tabulation
// Time Complexity: O(N*N)

// Reason: There are two nested loops

// Space Complexity: O(N)

// Reason: We are using an external array of size ‘N’ to store only one row.
    
      int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
          
        for(int j = 0 ; j < triangle[n-1].size() ; j++) dp[n-1][j] = triangle[n-1][j];
         
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                int l = dp[i+1][j];
                int r = dp[i+1][j+1];
               
        
                dp[i][j] = triangle[i][j] + min(l,r);
            }
        }
          
        return dp[0][0];
       
    }
};