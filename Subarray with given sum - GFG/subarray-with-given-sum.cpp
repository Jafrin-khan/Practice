// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here// Your code here
        vector<int> ans;
        int l = 0;
        int r = 0;
        int i;
        int j;
        long long sum = 0L;
        while(sum != s && l < n){
            
           
            if(sum < s){
                sum += arr[r];
                r++;
            }
            
            else if(sum > s){
                sum -= arr[l];
                l++;
            }
            
             if(sum == s){
                i = l + 1;
                j = r ;
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            
            
        }
        ans.push_back(-1);
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends