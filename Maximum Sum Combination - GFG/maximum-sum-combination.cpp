//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        
       sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    
    vector<int> ans;

   priority_queue<pair<int,pair<int,int>>> pq;//<sum , <i,j>>

    set<pair<int,int>> st;

    pq.push({a[n-1] + b[n-1] , {n-1 , n-1}});
    st.insert({n-1 , n-1});

    while(!pq.empty()){
        if(ans.size() == k) break;

        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;pq.pop();

        ans.push_back(sum);

        if(i-1 >= 0){
            if(st.find({i-1 , j}) == st.end()){
                pq.push({a[i-1] + b[j] , {i-1 , j}});
                st.insert({i-1 , j});
            }
        }

        if(j-1 >= 0){
            if(st.find({i , j-1}) == st.end()){
                pq.push({a[i]+b[j-1] , {i , j-1}});
                st.insert({i , j-1});
            }
        } 
    }

    
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends