//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

   bool isValid(int c , int node , int v , bool graph[101][101] , vector<int>& color){
       for(int i = 0 ; i < v ; i++){
           if(node != i && (graph[node][i] == 1 || graph[i][node] == 1) && color[i] == c) return false;
       }
       return true;
   }
    
    bool f(int node , vector<int>& color ,  bool graph[101][101], int m, int v){
    
        if(node == v) return true;
        
        for(int c = 0 ; c < m ; c++){
            if(isValid(c , node , v , graph , color)){
                color[node] = c;
                if(f(node+1 , color , graph , m , v)) return true;
                color[node] = -1;
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int v) {
        
        vector<int> color(v , -1);
        
         return f(0 , color , graph, m, v) ;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends