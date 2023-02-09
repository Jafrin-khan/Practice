//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /*
    TC = O(N)
    SC = O(N)
    */
    
    bool canPair(vector<int> nums, int k) {
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            nums[i] = nums[i]%k;
        }
        
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(k - nums[i]) != mp.end()){
                mp[k - nums[i]]--;
                if(mp[k - nums[i]] == 0) mp.erase(k - nums[i]);
            }
            else if(nums[i] == 0) continue;
            else mp[nums[i]]++;
        }
        
        return mp.size() == 0;
       
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends