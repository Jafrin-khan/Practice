class Solution {
public:
    
    
   
    int numTrees(int n) {
           
       vector<int> dp(n+1,0);
        
        dp[1] = 1;
        dp[0] = 1;
        int n1,n2;
        int sum;
       
        for(int ind = 2 ; ind <= n ; ind++){
            
             for (int i = 1; i <= ind; i++) {
 
                    // Recursive calls
                    n1 = dp[i - 1];
                    n2 = dp[ind - i];
                    dp[ind] += n1 * n2;
                }

                // Return the nth Catalan number
                 
            
        }
        return dp[n];
        
    }
};