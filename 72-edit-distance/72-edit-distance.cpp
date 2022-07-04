class Solution {
public:
    
    int f(int i , int j , string s1 , string s2 ,  vector<vector<int>>& dp){
        
        if(i < 1){
            return j;
        }
        
        if(j < 1){
            return i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i-1] == s2[j-1]){
            return f(i-1 , j-1 , s1 , s2 , dp);
        }
        
        else{
            
            int insert = 1 + f(i+1-1 , j-1 , s1 , s2, dp);
            int del = 1 + f(i-1 , j , s1 ,s2, dp);
            int replace = 1 + f(i-1,j-1,s1,s2, dp);
            
            return dp[i][j] = min({insert,del,replace});
            
        }
        
    
    }
    int minDistance(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m , n , s1 , s2, dp);
        
    }
};