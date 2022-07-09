// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        
        unordered_map<int,int> mp;
        int sum = nums[0];
        int len = 0;
        mp[nums[0]] = 0;
        for(int i = 1 ; i < n ; i++){
            
            sum += nums[i];
            
            if(sum == 0){
                len = i+1;
            }
            if(mp.find(sum) != mp.end()){
                len = max(len , i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        
        return len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends