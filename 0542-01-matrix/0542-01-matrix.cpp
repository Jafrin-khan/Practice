class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        vector<vector<int>> ans;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m , 0));
        vector<vector<int>> dis(n , vector<int>(m , 0));
        
        queue<pair<pair<int,int> , int>> q;//<<x,y>,steps>
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i , j},0});
                }
            }
        }
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;q.pop();
            
            dis[x][y] = steps;
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({{nx , ny} , steps + 1});
                }
            }
            
        }
        
        return dis;
        
    }
};