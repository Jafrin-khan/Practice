//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int entry[], int exit[], int n)
	{
	    sort(entry , entry + n);
	    sort(exit , exit + n);
	    
	    int i = 0 , j = 0 , minTime = entry[0];
	    int curr = 0 , res = 0;
	    
	    while(i < n && j < n){
	        if(entry[i] <= exit[j]){
	            curr++;
	            i++;
	        }
	        
	        else{
	            curr--;
	            j++;
	        }
	        
	        if(curr > res){
	            res = curr;
	            minTime = entry[i-1];
	        }
	    }
	    
	    return {res,minTime};
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends