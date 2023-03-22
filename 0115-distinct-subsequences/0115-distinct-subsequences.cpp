class Solution {
public:
    /*
    //Recursion
   // TC = O(2^N*2^M)
   // SC = O(N + M)
    
    int f(int i , int j , string s1 , string s2){
            if(j < 0) return 1;
            if(i < 0) return 0;
        
        if(s1[i] == s2[j]){ // found a match
            int take = f(i-1 , j-1 , s1 , s2);
            int notTake = f(i-1 , j , s1 , s2);
            
            return take + notTake;
        }
        
        else return f(i-1 , j , s1 , s2); //doesn't found a match
    }
    
    int numDistinct(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        return f(n-1 , m-1 , s1 , s2);
    }
    */
    
    
    /*
    //Memoization
    //TC = O(N*M)
    //SC = O(N*M) + O(N+M)
    
    
    int f(int i , int j , string s1 , string s2 , vector<vector<int>>& dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]){ // found a match
            int take = f(i-1 , j-1 , s1 , s2 , dp);
            int notTake = f(i-1 , j , s1 , s2 , dp);
            
            return dp[i][j] = take + notTake;
        }
        
        else return dp[i][j] = f(i-1 , j , s1 , s2 , dp); //doesn't found a match
    }
    
    int numDistinct(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        
        return f(n , m , s1 , s2 , dp);
    }
    */
    
    //Tabulation
    //TC = O(N*M)
    //SC = O(N*M)
    
    int numDistinct(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i-1] == s2[j-1]){ // found a match
                    long long take = dp[i-1][j-1];
                    long long notTake = dp[i-1][j];
                    dp[i][j] = take + notTake;
            }
        
                else  dp[i][j] = dp[i-1][j]; //doesn't found a match
            }
        }
        
        return dp[n][m];
    }
};