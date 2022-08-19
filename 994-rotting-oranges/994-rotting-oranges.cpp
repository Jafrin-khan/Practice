class Solution {
public:
    
    int dx[4] = {0 , 0 , -1 , 1};
    int dy[4] = {-1 , 1 , 0 , 0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        
          
         if(grid.size() == 0){
            return 0;
        }
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int tot = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                
                if(grid[i][j] != 0){
                    tot++;
                }
            }
        }
        
        int k = 0;
        int mins = -1;
        
        while(!q.empty()){
            
            int currSize = q.size();
            k+=currSize;
            mins++;
            
            while(currSize--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx , ny});
                    }
            }
            }
            
        }
        
        if(mins == -1){
            mins = 0;
        }
        
        return   k == tot?mins : -1;
        
    }
};