//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
        long long int sumOfDigits(int num){
            long long sum = 0;
            while(num){
                sum += (num%10);
                num/=10;
            }
            return sum;
        }
        
        long long int numberCount(long long int N, long long int K)
        {
            int ans = 0;
            while(N){
                int sum = sumOfDigits(N);
                if(N - sum >= K) ans++;
                N--;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n, k;
		cin >> n >> k;
		Solution ob;
		cout <<ob.numberCount(n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends