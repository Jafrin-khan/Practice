//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
 long long merge(long long arr[] , long long start , long long mid , long long end){
        
        long long cnt = 0;
        
        long long i = start;
        long long j = mid+1;
        
        vector<long long> temp(end-start+1);
        long long k = 0;
        
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else{
                cnt += (mid+1-i);
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
         while(j <= end){
            temp[k++] = arr[j++];
        }
        
        k = 0;
        for(long long i = start ; i <= end ; i++){
            arr[i] = temp[k++];
        }
        
        return cnt;
    }
    
    long long mergeSort(long long arr[] , long long start , long long end){
        
        
        long long cnt = 0;
        
        if(start < end){
        long long mid = (start + end)/2;
        cnt += mergeSort(arr , start , mid);
        cnt += mergeSort(arr , mid+1 , end);
        cnt += merge(arr , start , mid , end);
        }
        
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr , 0 , n-1);
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends