class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
         if(grid.size() == 0){
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        
        int tot = 0;
        queue<pair<int,int>> rotten;
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    rotten.push({i,j});
                }
                
                if(grid[i][j] != 0){
                    tot++;
                }
            }
        }
        int mins = 0;
        
        int dx[4] = {0 , 0 , 1 ,-1};
        int dy[4] = {1, -1 , 0 , 0};
        
        while(!rotten.empty()){
            
            int k = rotten.size();
            cnt += k;
            
            while(k--){
            int x = rotten.front().first;
            int y = rotten.front().second;
             rotten.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1){
                    continue;
                }
                
                grid[nx][ny] = 2;
                rotten.push({nx,ny});
            }
           
        }
            
            if(!rotten.empty()){
                mins++;
            }
        } 
                return tot == cnt ? mins : -1;
    }
};