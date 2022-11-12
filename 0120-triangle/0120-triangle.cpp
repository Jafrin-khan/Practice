class Solution {
public:
    
    /*Time Complexity: O(N*N)

Reason: At max, there will be (half of, due to triangle) N*N calls of recursion.

Space Complexity: O(N) + O(N*N)

Reason: We are using a recursion stack space: O((N), where N is the path length and an external DP Array of size ‘N*N’.*/
    
    int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp) {
		if(i == n - 1)
			return triangle[i][j];
		if(dp[i][j] != -1)
			return dp[i][j];
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
		return dp[i][j] = min(bottom, bottom_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		return solve(0, 0, n, triangle, dp);
	}
   
   
};



