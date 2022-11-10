class Solution {
public:
    
    /*
    TC = O(n) + O(n)
    SC = O(n)
    
    Time Complexity: O(N)

    Reason: The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve    is ‘n’. Hence total time complexity is O(N).

    Space Complexity: O(N)

    Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
    */

    int f(int n , vector<int>& dp){

        if(n == 1){
            return 1;
        }

        if(n == 2){
            return 2;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int one = f(n-1 , dp);
        int two = f(n-2 , dp);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {

        vector<int> dp(n+1 , -1);
        return f(n , dp);
    }
};