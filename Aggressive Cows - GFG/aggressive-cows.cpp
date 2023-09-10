//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossible(int miniDis , int cows , int n , vector<int>& stalls){
        
        int c = 1;
        int lastPlaced = stalls[0];
        
        for(int i = 1 ; i < n ; i++){
            if(stalls[i] - lastPlaced >= miniDis){
                c++;
                lastPlaced = stalls[i];
            }
        }
        
        return c >= cows;
    }

    int solve(int n, int cows, vector<int> &stalls) {
        
        sort(stalls.begin() , stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(mid , cows , n , stalls)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends