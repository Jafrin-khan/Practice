// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool f(int ind , int target , int n , int arr[] ,  vector<vector<int>>& dp){
        
        if(target == 0){
            return true;
        }
        
        if(ind == 0){
            return false;
        }
        
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        bool notPick = f(ind - 1 , target , n , arr , dp);
        bool pick = false;
        if(arr[ind] <= target){
            pick = f(ind - 1 , target - arr[ind] , n , arr , dp);
        }
        
        return dp[ind][target] = pick || notPick;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int target = 0;
        
        for(int i = 0 ; i < n ; i++){
            target += arr[i];
        }
        
        if(target%2 != 0){
            return 0;
        }
        
        target /= 2;
        
        vector<vector<int>> dp(n , vector<int>(target+1,-1));
        return f(n-1 , target , n , arr , dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends