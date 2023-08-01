//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossible(int minDis , int cows , vector<int>& stalls){
        
        int cnt = 1;
        int currPos = stalls[0];
        
        for(int i = 1 ; i < stalls.size() ; i++){
            if(stalls[i] - currPos >= minDis){
                currPos = stalls[i];
                cnt++;
                
                if(cnt == cows) return true;
            }
        }
        
        return false;
    }

    int solve(int n, int cows, vector<int> &stalls) {
    
        sort(stalls.begin() , stalls.end());
        
        int low = stalls[1] - stalls[0];
        int high = stalls[n-1] -stalls[0];
        
        for(int i = 1 ; i < n ; i++){
            low = min(low , stalls[i] - stalls[i-1]);
        }
        
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(isPossible(mid , cows , stalls)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
        
    }
    //  0 1 2 3 4
    // [1 2 4 8 9]
    //  c1  c2 c3  
    
    // low = 4
    // high = 3
    
    // mid = 3
    // ans = 2
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