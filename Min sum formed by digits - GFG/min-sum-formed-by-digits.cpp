//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*
    TC = O(N)
    SC = O(N)
    */
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        if(n == 0) return arr[0];
        
        priority_queue<long long , vector<long long> , greater<long long>> pq;
        
        for(long long i = 0 ; i < n ; i++){ pq.push(arr[i]);}
        
        long long n1 = 0 , n2 = 0;
        while(pq.size()){
            long long top1 = pq.top();pq.pop();
            n1 = n1*10 + top1;
            
            if(pq.empty()) break;
            
            long long top2 = pq.top();pq.pop();
            n2 = n2*10 + top2;
        }
        
        return n1+n2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends