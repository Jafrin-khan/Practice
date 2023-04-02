//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int min_soldiers(int arr[], int n, int k);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n, k;
        cin>> n >> k;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        cout << min_soldiers(arr, n, k) << endl;
        
    }
	
	return 0;
}
// } Driver Code Ends


int min_soldiers(int arr[], int n, int k){
    
    
    int ans = 0;
    int cnt = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(arr[i]%k == 0) cnt++;
        if(cnt >= (n+1)/2) return 0;
    }
    
    for(int i = 0 ; i < n ; i++){ arr[i]%=k;} //eg elem is 9 and k is 4 then 9 has to be incremented by 3...hence we form a mod 9%4 == 1 and we simply iterate in other loop to get ans += (k-arr[i]) ,ie, 4-1 == 3
    
    sort(arr , arr + n);//pehle se sort krne ka faayda ni is particular position pe sort krna hoga coz hmein resultant mod vals ko sort krna hai
    
    int i = n-1;
    //loop usli direction m islie chlaare bcoz of the case :
/*
    2 17
    9 11
    
Your Code's output is: 8 //agr hum i = 0 se iterate kreyy
It's Correct output is: 6
*/
    while(i >= 0){
           if(arr[i] != 0) {//mod ki wajah se divisible waale sb zero ho gye aur waise bhi wo pehle hi cnt m consider kr lie theyy humne
               ans += (k-arr[i]);
               cnt++;
           }
            if(cnt >= (n+1)/2) break;
            i--;
    }
    return ans;
}