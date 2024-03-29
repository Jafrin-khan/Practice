//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
         sort(arr,arr+n);
        int count =0;
        
        for(int i=n-1;i>=0;i--){
            int s=0;
            int e =i-1;
            
            while(s<=e){
                if(arr[s]+arr[e]>arr[i]){
                    count = count+(e-s); // cnt mai hum (e-s) islie add krrey coz agr arr[s] + arr[e] > arr[i] to arr[s+1]+arr[e] aur arr[s+2]+arr[e]..and so on bhi bde hue coz array ascending order mai hai islie saara cnt consider krke e-- kr diya
                    e--;
                }
                else
                s++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends