class Solution {
public:
    
    void bfs(int i , int j , int n , int m , vector<vector<char>>& grid , vector<vector<int>>& vis){
        
        queue<pair<int,int>> q; //<x,y>
        q.push({i,j});
        vis[i][j] = 1;
        
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 ,-1 , 1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                } 
            }
        
    }}
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == '1') {
                    bfs( i , j , n , m , grid , vis);
                    cnt++;
                }
                
            }
        }
        
        return cnt;
    }
};