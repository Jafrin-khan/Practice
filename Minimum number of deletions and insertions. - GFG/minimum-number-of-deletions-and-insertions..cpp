//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int f(int i , int j , string s1, string s2 , vector<vector<int>>& dp){
	    
	    if(i < 0) return j + 1;
	    if(j < 0) return i + 1;
	    
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    if(s1[i] == s2[j]) return dp[i][j] = f(i - 1 , j - 1 , s1 , s2 , dp);
	    
	    else{
	        int insertions = 1 + f(i , j - 1 , s1 , s2 , dp);
	        int deletions = 1 + f(i - 1 , j , s1 , s2 , dp);
	        
	        return dp[i][j] = min(insertions , deletions);
	    }
	}
	
	int minOperations(string s1, string s2) 
	{ 
	   int n = s1.size();
	   int m = s2.size();
	   
	   vector<vector<int>> dp(n , vector<int>(m , -1));
	   
	   return f(n - 1 , m -1 , s1 , s2 , dp);
	  
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends