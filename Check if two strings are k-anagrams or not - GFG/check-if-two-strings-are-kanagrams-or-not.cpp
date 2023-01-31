//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string s1, string s2, int k) {
        // code here
        if(s1.size() != s2.size()) return false;
        
        unordered_map<char,int> mp;
        
        for(int i = 0 ; i < s1.size() ; i++){
            mp[s1[i]]++;
        }
        
        for(auto it : s2){
            if(mp.find(it) != mp.end()){
                mp[it]--;
                if(mp[it] == 0) mp.erase(it);
            }
        }
        
        int cnt = 0;
        for(auto it : mp){
            cnt += it.second;
        }
        
        if(cnt <= k)return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends