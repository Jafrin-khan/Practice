//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies , candies + n);
        
        vector<int> ans;
        
        int cnt = 0 , i = 0;
        int mini = 0 , maxi = 0;
        
        while(i < n){
            mini += candies[i++];
            cnt += k+1;
            if(cnt >= n){ ans.push_back(mini); break;}
        }
        
        i = n-1 , cnt = 0;
        
        while(i >= 0){
            maxi += candies[i--];
            cnt += k+1;
            if(cnt >= n){ ans.push_back(maxi);break;}
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends