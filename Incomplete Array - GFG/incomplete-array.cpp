//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countElements(int N, int A[]) {
        // code here
        
        set<int> st;
        int maxi = -1e9 , mini = 1e9;
        for(int i = 0 ; i < N ; i++){
            maxi = max(maxi , A[i]);
            mini = min(mini , A[i]);
            st.insert(A[i]);
        }
        
        return (maxi - mini-1 - st.size()+2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}
// } Driver Code Ends