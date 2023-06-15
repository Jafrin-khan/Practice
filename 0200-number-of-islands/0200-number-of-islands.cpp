class Solution {
public:
    
    void bfs(int i , int j , vector<vector<char>>& grid , int n , int m){
        
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '$';
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1'){
                    q.push({nx , ny});
                    grid[nx][ny] = '$';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    bfs(i , j , grid, n , m);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};  