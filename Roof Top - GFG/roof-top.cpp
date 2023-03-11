//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int nums[], int n)
    {
       //Your code here
       int ans = 0;
       int cnt = 0;
       for(int i = 1 ; i < n ; i++){
           if(nums[i] <= nums[i-1]){
               cnt = 0;
           }
           else{ 
               cnt++;
           }
           ans = max(ans , cnt);
       }
       
       return ans;
    }
};

//{ Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends