//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends


class Solution{
    public:
    int emptyLanes(pair<int, int> a[], int n, int tracks) {
        
        sort(a , a + n);
        int ans = 0;
        int s = a[0].first;
        int e = a[0].second;
        ans += e-s+1;
        
        for(int i = 1 ; i < n ; i++){
            int x = a[i].first;
            int y = a[i].second;
            
            if(x > e){
             s = x;
             e = y;
             ans += (y-x+1);
            } 
         
            else if(x <= e && y > e){//agr x aur y dono hi chote h s aur e se repectively to wo interval consider hi ni hoga..number line bnaake dekho
                ans += (y-e);
                e = y;//start wahi choti waali value rahegi coz ye to merge waali condition aa gyi yhan pe
            }
            
            
        }
        
        return tracks-ans;
    }
};

//{ Driver Code Starts.
int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n, l1, l2, i, tracks;
        cin >> n >> tracks;
        pair<int, int> a[n];
        for (i = 0; i < n; i++) {
            cin >> l1 >> l2;
            a[i].first = l1;
            a[i].second = l2;
        }
        Solution ob;
        cout << ob.emptyLanes(a, n, tracks) << endl;
    }
    return 0;
}
// } Driver Code Ends