//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
      map<int,vector<int>, greater<int>> map;//dec order
      for(int i=0; i<n; i++)
      {
          int j=arr[i];
          int c=0;
           while(j)
           {
             if(j%2==1)
             c++;
              j=j/2;
           }
           map[c].push_back(arr[i]);
      }
      int index=0;
      for (auto it : map) {
     
        for (auto i : it.second){
            arr[index++]=i;
        }
    }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends