//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n){
	  
	  int low = 0;
	  int high = n-1;
	  
	  while(low < high){
	      
	      int mid = low + (high - low) / 2;
	      if(mid > low && arr[mid-1] > arr[mid]) return mid;
	      else if(mid < high && arr[mid+1] < arr[mid]) return mid+1;
	      
	      if(arr[high] > arr[mid]) high = mid-1;
	      else low = mid + 1;
	      
	  }
	  return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends