// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int> ans;
            int i = 0, j = 0 , cnt = 0;
            
            while(i < txt.size()){
                
                if(txt[i] == pat[0]){
                    int ind = i;
                    int j = 0;
                    
                    while(i < txt.size()){
                      
                        
                        if(txt[i] == pat[j]){
                            i++;
                            j++;
                        }
                        
                        else{
                            break;
                        }
                          if(j == pat.size()){
                            ans.push_back(ind+1);
                            break;
                        }
                    }
                    
                    i = ind+1;
                    
                    }
                    
                    
                    else{
                        i++;
                }
            }
                if(ans.empty()){
                    ans.push_back({-1});
                }
                
                return ans;
            }
        
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends