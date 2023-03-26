//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes(vector <vector <int>> &nums, int n, int m)
        {   
            
            int maxi = 0; 
            int row = 0; 
            
            for(int i = 0 ; i < n ; i++){
                int low = 0;
                int high = m-1;
                int curr = 0;
                while(low <= high){
                    int mid = (low + high)/2;
                    
                    if(nums[i][mid] == 1){
                        curr = max(curr , m - mid);
                        high = mid-1;
                    }
                    
                    else{
                        low = mid+1;
                    }
                }
                
                if(curr > maxi){
                    maxi = curr;
                    row = i;
                }
            }
            
            return row;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends