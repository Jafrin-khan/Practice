//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> end) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n , vector<int>(m , 1e9));
        
        queue<pair<pair<int,int>,int>> q; //<<i,j>,cost>
        q.push({{src.first , src.second} , 0});
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            
            int cost = q.front().second;q.pop();
            
            if(x == end.first && y == end.second){
                return cost;
            }
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && dis[nx][ny] > 1 + cost) {
                    dis[nx][ny] = cost + 1;
                    q.push({{nx , ny},cost+1});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends