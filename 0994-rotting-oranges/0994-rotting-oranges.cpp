class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> rotten;//<i , j>
        int tot = 0;
        int rot = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2) {
                    rot++;
                    rotten.push({i,j});
                }
                if(grid[i][j] != 0) tot++;
            }
        }
        
        if(rot == tot) return 0;/////////////////////
        
        int time = -1;
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!rotten.empty()){
            
            int size = rotten.size();//////////////////////////////////////////
            time++;
            
            while(size--){////////////////////////////////
            int x = rotten.front().first;
            int y = rotten.front().second; rotten.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                    rotten.push({nx,ny});
                    grid[nx][ny] = 2;/////////////////////////
                    rot++;
                }
            }
        }
        }
        return rot == tot ? time : -1;
    }
};