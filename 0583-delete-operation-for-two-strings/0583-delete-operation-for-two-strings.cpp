class Solution {
public:
    
     /*
    Recursive
    TC = O(N*M)
    SC = O(N*M)
    */
    /*
    int lcs(int i , int j , string s1 , string s2){
        
        if(i < 0 || j < 0) return 0;
        
        if(s1[i] == s2[j]) return 1 + lcs(i-1 , j-1 , s1 , s2);
        
        int a = lcs(i-1,j-1,s1,s2);
        int b = lcs(i-1,j,s1,s2);
        int c = lcs(i,j-1,s1,s2);
        
        return max({a,b,c});
        
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        //deletions in 1st string n-lcs
        //insertions in 1st string m-lcs ,i.e, deletions in m
        //steps = (n+m)-2*lcs
        
        return (n+m) - 2*lcs(n-1,m-1,word1,word2);
    }*/
    
    /*
    memoised
    TC = O(N*M)
    SC = O(N*M) + O(N*M)
    */
    int lcs(int i , int j , string s1 , string s2,vector<vector<int>>& dp){
        
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + lcs(i-1 , j-1 , s1 , s2,dp);
        
      //  int a = lcs(i-1,j-1,s1,s2,dp);
        int b = lcs(i-1,j,s1,s2,dp);
        int c = lcs(i,j-1,s1,s2,dp);
        
        return dp[i][j] = max({b,c});
        
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        //deletions in 1st string n-lcs
        //insertions in 1st string m-lcs ,i.e, deletions in m
        //steps = (n+m)-2*lcs
        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
        
        return (n+m) - 2*lcs(n-1,m-1,word1,word2,dp);
    }
};