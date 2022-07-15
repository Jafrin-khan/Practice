class Solution {
public:

    int minScoreTriangulation(vector<int>& values) {
       
       int n = values.size();
       vector<vector<int>> dp(n , vector<int>(n,0));
      
        
      for(int i = n-1 ; i >= 1 ; i--){
          for(int j = i+1 ; j < n ; j++){
               int mini = 1e9;
                for(int k = i ; k < j ; k++){
                int steps = values[i-1]*values[k]*values[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini , steps);
        }
        
      dp[i][j] = mini;
              
          }
      }
        
      return dp[1][n-1];
        
    }
};