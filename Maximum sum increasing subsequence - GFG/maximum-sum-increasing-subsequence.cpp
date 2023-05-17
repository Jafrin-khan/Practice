//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    /*
	    //Why printing the LIS code not working!....coz.. "Find the sum of the maximum sum subsequence" likha hai wo susequence LIS ho zaruri ni
	    vector<int> dp(n , 1);
	    vector<int> hash(n);
	    
	    int maxi = 1;
	    
	    int lastIndex = 0;
	    
	    for(int ind = 0 ; ind < n ; ind++){
	        hash[ind] = ind;
	        for(int prev = 0 ; prev <= ind-1 ; prev++){
	            if(arr[prev] < arr[ind] && dp[prev] + 1 > dp[ind]){
	                dp[ind] = dp[prev]+1;
	                hash[ind] = prev;
	            }
	        }
	        
	        if(dp[ind] > maxi){
	            maxi = dp[ind];
	            lastIndex = ind;
	        }
	    }
	    
	    int sum = arr[lastIndex];
	    
	    while(hash[lastIndex] != lastIndex){
	        lastIndex = hash[lastIndex];
	        sum += arr[lastIndex];
	        
	    }
	    
	    return sum;
	    */
	    
	    //lekin rooh algo ki LIS wala concept hi hai bs twisted hai
	    
	    vector<int> dp(n,0);
	    dp[0] = arr[0];
	    int maxi = arr[0];
	    
	    for(int ind = 1 ; ind < n ; ind++){
	        dp[ind] = arr[ind];
	        for(int prev = 0 ; prev <= ind-1 ; prev++){
	            if(arr[prev] < arr[ind]) dp[ind] = max(dp[ind] , dp[prev] + arr[ind]);
	        }
	        
	        maxi =   max(maxi , dp[ind]);
	    }
	    
	    return maxi;
	    
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends