//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long maxProfit(int a[], int n, int m);

int main()
 {
     ll t;
     cin>>t;
     while(t--)
     {
         int n,m;
         cin>>n>>m;
         int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         
         cout<< maxProfit(a, n, m) <<endl;
     }
	
	return 0;
}


// } Driver Code Ends


long long maxProfit(int a[], int n, int m)
{
      sort(a , a + n);
      
      long long profit = 0;
      
      int i = 0;
      while(i < n && i < m){
          if(a[i] < 0) profit += abs(a[i]);
          i++;
      }
      
      return profit;
}