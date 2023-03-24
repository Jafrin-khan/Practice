//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<int> square(int arr[], int n);


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int> ans;
        ans = square(arr, n);
        for(int i:ans)
            cout << i << " ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends


vector<int> square(int arr[], int n)
{
    // Complete the function
    
    unordered_map<int,int> mp;
    
    int cnt = -1;
    int maxArea = -1;
    
    for(int i = 0 ; i < n ; i++){
        mp[arr[i]]++;
    }
    
    for(auto it : mp){
        if(it.second >= 4){
            int side = it.first;
            if(side*side > maxArea){
                maxArea = side*side;
                cnt = it.second/4;
            }
        }
    }
    
    if(maxArea == -1 && cnt == -1) return {-1};
    
    return {maxArea,cnt};
}
