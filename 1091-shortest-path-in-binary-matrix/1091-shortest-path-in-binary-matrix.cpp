class Solution {
public:
    
    /*
Time Complexity: O( 8*N*M ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the shortest path length}, Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.

Space Complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
    
    */
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1){
            return grid[0][0] == 0;
        } 
       
        vector<vector<int>> distTo(n , vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        
        q.push({1,{n-1,n-1}});
        distTo[n-1][n-1] = 1;
        int ans = 1e9;
        
        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;q.pop();
            
             for(int i = -1 ; i <= 1 ; i++){
                 for(int j = -1 ; j <= 1 ; j++){
                     int nx = x + i;
                     int ny = y + j;
                     
                     if(nx < 0 || ny < 0 || nx >= n || ny >= n || (nx == x && ny == y) || grid[nx][ny] == 1) continue;
                     if(nx == 0 && ny == 0 && grid[nx][ny] == 0) ans = min(ans , dis+1);
                     if(distTo[nx][ny] > dis + 1){
                         distTo[nx][ny] = dis+1;
                         q.push({dis+1,{nx,ny}});
                     }
                     
                 }
             }
        }
        if(ans == 1e9) return -1;
        
        return ans;
        
    }
};