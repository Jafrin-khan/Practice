// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ind = 0;
        int i = 0;
        int j = 0;
        
        int arr[n+m];
        
        while(i < n && j < m){
             
             if(arr1[i] <= arr2[j]){
                 arr[ind++] = arr1[i++];
             }
             
             else{
                 arr[ind++] = arr2[j++];
             }
        }
        
        while(i < n){
            arr[ind++] = arr1[i++];
        }
        
        while(j < m){
            arr[ind++] = arr2[j++];
        }
        
        i = 0;
        int ans = 0;
        for(i = 0 ; i < (m+n) ; i++){
            
            if(i == k-1){
                ans = arr[i];
            }
        }
       return ans; 
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends