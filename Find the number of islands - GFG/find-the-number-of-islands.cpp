//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
     void bfs(int i , int j ,vector<vector<char>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i , j});
         grid[i][j] = '$';
        
        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int r = -1 ; r <= 1 ; r++){
                for(int c = -1 ; c <= 1 ; c++){
                    
                    //simple logic, jb dono change hore h to diagnally krre h ,abhi zroorat ni isliye ye condition
                    
                    int nrow = r + row;
                    int ncol = c + col;
                  
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1'){
                        grid[nrow][ncol] = '$';
                        q.push({nrow , ncol});
                    }
                }
            }
        }
    
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
         int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j ++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i , j , grid);
                }
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends