//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:

    //https://www.youtube.com/watch?v=IWEVmB8QF2k
    
	int countZeros(vector<vector<int>>& nums)
	{
	    int ans = 0;
	    
	    int n = nums.size();
	    int m = nums[0].size();
	    
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(nums[i][j] == 0) ans++;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}

// } Driver Code Ends