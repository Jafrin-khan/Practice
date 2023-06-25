class Solution {
public:
    
    //03/18/2023
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        if(n == 1){
            return grid[0][0] == 0;
        } 
        
        vector<vector<int>> disTo(n , vector<int>(m , 1e9));
        queue<pair<int,pair<int,int>>> q;
        
        q.push({1,{n-1,m-1}});
        disTo[n-1][m-1] = 1;///////////////////////////////////
        int ans = 1e9;
        
        while(!q.empty()){
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;q.pop();
            
            for(int i = -1 ; i <= 1 ; i++){
                for(int j = -1 ; j <= 1 ; j++){
                    int nx = i + x;
                    int ny = j + y;
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || (nx == x && ny == y) || grid[nx][ny] == 1) continue;
                    
                    if(nx == 0 && ny == 0) ans = min(ans , d + 1);
                    if(disTo[nx][ny] > d + 1){
                        disTo[nx][ny] = d + 1;
                        q.push({disTo[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        
        if(ans == 1e9) return -1;
        
        return ans;
        
    }
};