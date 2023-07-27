//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int f(vector<int>& row , vector<vector<int>> &matrix , int c , int num){
        
        int low = 0;
        int high = c-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(row[mid] <= num) low = mid+1;
            else high = mid-1;
        }
        
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        
        int low = 1;
        int high = 1e9;
        
        int medianNum = (r*c)/2;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int cnt = 0;
            for(int row = 0 ; row < r ; row++){
                cnt += f(matrix[row] , matrix , c , mid);
            }
            
            if(cnt <= medianNum) low = mid+1;
            else high = mid-1;
        }
        
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends