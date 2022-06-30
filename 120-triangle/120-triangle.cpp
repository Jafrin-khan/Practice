class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        
        if(i == triangle.size()-1){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int dl = triangle[i+1][j] + f(i+1 , j , triangle , dp);
        int dr = triangle[i+1][j+1] + f(i+1 , j+1 , triangle , dp);
        
        return dp[i][j] = min(dl , dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return f(0 , 0 , triangle , dp) + triangle[0][0];
        
    }
};