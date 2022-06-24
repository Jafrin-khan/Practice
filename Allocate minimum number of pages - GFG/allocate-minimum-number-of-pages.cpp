// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isPossible(int a[] , int n , int pages , int students){
        
        
        int count = 0;
        int sumAllocated = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(sumAllocated + a[i] > pages){
                sumAllocated = a[i];
                count++;
            
            
            if(sumAllocated > pages){
                return false;
            }
            } 
            else{
                sumAllocated += a[i];
            }
        }
        
        if(count < students){
            return true;
        }
        
        return false;
        
    }
    int findPages(int a[], int n, int m) 
    {
        //code here
        
        if(m > n){
            return -1;
        }
        
        int low = INT_MAX;
        int high = 0;
        
        for(int i = 0 ; i < n ; i++){
            low = min(low,a[i]);
            high+=a[i];
        }
        
        while(low <= high){
            
            int mid = (low+high)/2;
            if(isPossible(a,n,mid,m)){
                high = mid - 1;
            }
            
            else{
                low = mid+1;
            }
        }
        
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends