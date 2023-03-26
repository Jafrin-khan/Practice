//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int nums[], int n) {

        if(n==1) return nums[0];

        //check if first or last element are peak
         if(nums[0]>nums[1]) return nums[0];
         if(nums[n-1]>nums[n-2]) return nums[n-1];

         //search in the remaining array
            int start=1;
            int end=n-2;

            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]>nums[mid+1] && nums[mid]> nums[mid-1])  return nums[mid]; //if index found
                else if(nums[mid]<nums[mid+1])   start=mid+1; //search in upward slope
                else if(nums[mid]>nums[mid+1])   end=mid;//search in downward slope
            }
        return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends