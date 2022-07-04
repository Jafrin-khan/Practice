class Solution {
public:
    
    int f(int i , int j , string s1 , string s2 ,  vector<vector<int>>& dp){
        
        if(i < 0){
            return j+1;
        }
        
        if(j < 0){
            return i+1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
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
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1 , n-1 , s1 , s2, dp);
        
    }
};