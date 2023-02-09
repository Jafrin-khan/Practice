//{ Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(int n, int arr[], int K){
        // code here
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
            if(mp[arr[i]] > 2*K) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>K;
        
        Solution ob;
        cout<<ob.isPossible(N, arr, K)<<"\n";
    }
    return 0;
}
// } Driver Code Ends