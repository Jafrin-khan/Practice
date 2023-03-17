class Solution {
public:
    /*
    //Recursion
    //TC = O(2^N)
    //SC = O(N)
*/
    
    //Memoised
//Time Complexity: O(N*K)

//Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

//Space Complexity: O(N*K) + O(N)

//Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
    int f(int ind , int target , vector<int>& nums , vector<vector<int>>& dp){
        
       //issi if k andar target == 0 waali condition likhni padegi coz hmaare saare elements consider krney h yhn..islie base case sirf ek h jb ind == 0 ho jaayga
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = f(ind-1 , target , nums , dp);
        int take = 0;
        if(nums[ind] <= target){
            take = f(ind-1 , target - nums[ind] , nums , dp);
        }
        return dp[ind][target] = take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int totSum = 0;
        
        for(int i = 0 ; i < n ; i++){totSum += nums[i];}
        
        int s2 = (totSum - target)/2;
        if((totSum - target) < 0 || (totSum-target)%2) return 0;
        
        vector<vector<int>> dp(n , vector<int>(s2+1 , -1));//imp. we are finding subset with targetSum 's2' hence dp array uska bna
        
        return f(n-1 , s2 , nums , dp);
        
    }
    
};