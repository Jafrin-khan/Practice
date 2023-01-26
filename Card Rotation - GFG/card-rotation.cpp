//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:    
  
    vector<int> rotation(int n)
    {
        // Code Heree
        deque<int> dq;
        for(int i = n ; i >= 1 ; i--){
            dq.push_front(i);
            for(int j = 0 ; j < i ; j++){
                int last = dq.back();
                dq.pop_back();
                dq.push_front(last);
            }
        }
        
        vector<int> ans;
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        
        if(ans.size() == n) return ans;
        return {-1};
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin >> n;
        vector<int > ans;
        ans = obj.rotation(n);
        for(int i:ans)
            cout<< i << " ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends