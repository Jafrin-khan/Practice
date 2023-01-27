//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    //TC = O(N)
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    for(int i = 0 ; i < n-1 ; i++){
	        int j = i+1;
	        if(arr[i] > arr[j])arr[i] = arr[j];
	        else arr[i] = -1;
	    }
	    
	    arr[n-1] = -1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends