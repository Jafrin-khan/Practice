// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool f(int ind , vector<int> nums,  int k , vector<vector<int>> &dp){
        
        if(k == 0){
            return true;
        }
        
        if(ind == 0){
         return nums[0] == k;
            
        }
        
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
        
        bool notPick = f(ind-1 , nums , k , dp);
        bool pick = false;
        if(nums[ind] <= k){
           pick = f(ind - 1 , nums , k - nums[ind] , dp);
        }
        
        return dp[ind][k] = (pick || notPick);
    }
    bool isSubsetSum(vector<int>nums, int k){
        // code here 
        
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(k+1,-1));
        return f(n-1 , nums , k , dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends