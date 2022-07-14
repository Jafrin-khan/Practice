// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    pair<int,int> ans;
    int fl = INT_MIN;
    int cl = INT_MAX;
    
    for(int it = 0 ; it < n ; it++){
        if(arr[it] <= x){
            fl = max(fl , arr[it]);
        }
        
        if(arr[it] >= x){
            cl = min(cl , arr[it]);
        }
    }
    
    if(fl == INT_MIN){
        fl = -1;
    }
    
    if(cl == INT_MAX){
        cl = -1;
    }
    
    ans.first = fl;
    ans.second = cl;
    
    return ans;
}