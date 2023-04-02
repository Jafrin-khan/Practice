//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
   
    void sortABS(int arr[],int n, int k)
    {
       vector<pair<pair<int,int>,int>>v;//<<diff,ind>,num>
       for(int i=0;i<n;i++){
           v.push_back({{abs(k-arr[i]),i},arr[i]});
       }
       sort(v.begin(),v.end());
       int p=0;
       for(auto it : v){
           arr[p] = it.second;
           p++;
       }
       
    }

};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    Solution ob;
	   
	    ob.sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends