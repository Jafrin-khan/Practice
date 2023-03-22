//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int mod = 100000;
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        vector<int> disArr(100000 , 1e9);
        queue<pair<int,int>> q; //<steps,node>
        
        q.push({0 , start});
        disArr[start] = 0;
        
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;q.pop();
            
            for(auto it : arr){
                int prod = (it*node)%mod;
                
                if(prod == end) return steps+1;
                
                if(disArr[prod] > steps+1){
                    disArr[prod] = steps+1;
                    q.push({steps+1,prod});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends