//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int n, int target){
   
    sort(arr , arr + n);

    int l = 0;
    int r = 1;
    
    while(l <= r && r < n){
        
        if(arr[r] - arr[l] == target && r!=l){
            return true;
        }
        
        else if(arr[r] - arr[l] > target){
            l++;
        }
        
        else{
            r++;
        }
        
    }
    
    return false;
    
}