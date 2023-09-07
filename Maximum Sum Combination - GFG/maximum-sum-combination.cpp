//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        
        set<pair<int,int>> st;
        priority_queue<pair<int , pair<int,int>>> pq; //<sum , <i , j>>
        
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        
        int i = n-1 , j = n-1;
        pq.push({{a[i] + b[i]} , {i , j}});
        st.insert({i , j});
        
        vector<int> ans;
        
        while(!pq.empty()){
            
            if(ans.size() == k) break;
            auto front = pq.top();
            int sum = front.first;
            
            int x = front.second.first;
            int y = front.second.second;pq.pop();
            
            ans.push_back(sum);
            
            if(x-1 >= 0){
                if(st.find({x-1 , y}) == st.end()){
                    st.insert({x-1 , y});
                    pq.push({a[x-1] + b[y] , {x-1 , y}});
                }
            }
            
            if(y-1 >= 0){
                if(st.find({x , y-1}) == st.end()){
                    st.insert({x , y-1});
                    pq.push({a[x] + b[y-1] , {x , y-1}});
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