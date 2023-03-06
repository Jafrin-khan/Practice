class Solution {
public: 
    /*
    TC = O(N*M) + O(N*M)
    SC = O(N*M)
    */
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        int tot = 0 , rotten = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    rotten++;
                    q.push({i,j});
                }
                
                if(grid[i][j] != 0) tot++;
            }
        }
        
        if(tot == rotten) return 0;
        
        int time = -1;
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(grid[nx][ny] == 1) {
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                        rotten++;
                    }
                }
                
            }
            
            time++;
        }
        
        return tot == rotten ? time : -1;
        
    }
};