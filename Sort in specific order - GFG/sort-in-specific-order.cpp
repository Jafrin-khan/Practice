//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    void sortIt(long long arr[], long long n)
    {
        vector<int>ans;
        sort(arr, arr+n);
        
        for(int i=n-1; i>=0; i--) if(arr[i]%2 != 0) ans.push_back(arr[i]);
        for(int i=0; i<n; i++) if(arr[i]%2 == 0) ans.push_back(arr[i]);
        
        for(int i=0; i<n; i++)arr[i] = ans[i];
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        Solution ob;
        ob.sortIt(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends