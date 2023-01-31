//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int firstElement(int arr[], int n, int k)
    {
         unordered_map<int,pair<int,int>> mp;//<val,pair<ind,freq>>
        
        for(int i = 0 ; i < n ; i++){
            if(mp.find(arr[i]) != mp.end()) mp[arr[i]].second++;
            else mp[arr[i]] = {i,1};
        }
       
        int ind = 1e9;
        int ans;
        for(auto it : mp){
            if(it.second.first < ind && it.second.second == k){
                ind = it.second.first;
                ans = it.first;
            }
        }
        
        if(ind == 1e9)return -1;
        
        return ans;
    
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		cout<<ob.firstElement(a,n,k)<<endl;
	}
	return 0;
}

// } Driver Code Ends