// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int nums[], int n, int k)
    {
        //code here.
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < k ; i++){
            mp[nums[i]]++;
        }
        
        int left = 0;
        int right = k;
        vector<int> ans;
        ans.push_back(mp.size());
        
        while(right < n){
         
            if(mp[nums[left]] == 1){
                mp.erase(nums[left]);
            }
            else{
                 mp[nums[left]]--;
            }
            mp[nums[right]]++;
            
            ans.push_back(mp.size());
            left++;
            right++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends