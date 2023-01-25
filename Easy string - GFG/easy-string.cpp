//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string s){
    
    int n = s.size();
    
    for(int i = 0 ; i < n ; i++){
        s[i] = tolower(s[i]);
    }
    
    int i = 0;
    string ans = "";
    while(i < n){
        int cnt = 1;
        int j = i+1;
        while(j < n && s[i] == s[j]){
            cnt++;
            j++;
        }
        ans += (to_string(cnt) + s[i]);
        i = j;
       
    }
    
    return ans;
}

