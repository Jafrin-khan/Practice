class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int tot = 0;
        int rot = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                    rot++;
                }
                if(grid[i][j] != 0) tot++;
            }
        }
        
        if(tot == 0) return 0;
        
        int time = -1;
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
            int x = q.front().first;
            int y = q.front().second;q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                rot++;
                q.push({nx,ny});
                grid[nx][ny] = 2;
            }
           
        }
             time++;
        }
        return tot == rot ? time : -1;
    }
};