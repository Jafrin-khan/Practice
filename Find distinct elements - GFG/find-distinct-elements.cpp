//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int distinct(vector<vector<int>> matrix, int n)
    {
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                //imp logic
                if(mp[matrix[i][j]] == i){
                 mp[matrix[i][j]]++;
                }
        }
        }
        
        int ans = 0;
        for(auto it : mp){
            if(it.second == n)ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends