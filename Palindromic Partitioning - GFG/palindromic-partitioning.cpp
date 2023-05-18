//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isValid(string s){
        int start = 0;
        int end = s.size()-1;
        
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        
        return true;
    }

    int f(string s , unordered_map<string,int>& dp){
        if(isValid(s)) return 0;
        int mini = s.size()-1;
        
        if(dp.find(s) != dp.end()) return dp[s];
        
        for(int i = 1 ; i < s.size() ; i++){
            string temp = s.substr(0,i);
            if(isValid(temp)){
                mini = min(mini , 1 + f(s.substr(i),dp));
            }
        }
        
        return dp[s] = mini;
    }
    int palindromicPartition(string s)
    {
        unordered_map<string,int> dp;
        return f(s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends