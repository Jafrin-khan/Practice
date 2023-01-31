//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        
        unordered_map<int,pair<int,int>> mp;//<val,pair<ind,freq>>
        
        for(int i = 0 ; i < n ; i++){
            if(mp.find(arr[i]) != mp.end()) mp[arr[i]].second++;
            else mp[arr[i]] = {i,1};
        }
       
        int ind = 1e9;
        for(auto it : mp){
            if(it.second.first < ind && it.second.second > 1){
                ind = it.second.first;
            }
        }
        
        if(ind == 1e9)return -1;
        
        return ind+1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends