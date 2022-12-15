class Solution {
public:
    
    /*
    
    Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M) + O(N x M) ~ O(N x M)

O(N x M) for the visited array, distance matrix, and queue space takes up N x M locations at max. 
    */
    
    /*
    TC = O(M*N)
    SC = O(M*N)
    */
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m , 0));
        vector<vector<int>> dis(n , vector<int>(m , 0));
        
        queue<pair<pair<int,int>,int>> q;
        
        
        //pushing ind of all 1s in grid and their corresponding dis ,i.e, 0
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int dx[] = {-1 , 0 , 1 , 0};
        int dy[] = {0 , 1 , 0 , -1};
        
        while(!q.empty()){
            
            auto front = q.front();
            q.pop();
            
            int x = front.first.first;
            int y = front.first.second;
            int d = front.second;
            
        
            dis[x][y] = d;
            
            
            for(int i = 0 ; i < 4 ; i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]){
                    continue;
                }
                
                vis[nx][ny] = 1;
                q.push({{nx,ny},d+1});
            
            }
            
            
        }
        
        return dis;
        
        
    }
};