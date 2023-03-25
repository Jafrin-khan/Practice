class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int n, int m, int sr, int sc) {
        
        vector<vector<int>> ans;
        vector<vector<int>> vis(n , vector<int>(m,0));
        
        queue<pair<int,int>> q;//<i,j>
        q.push({sr , sc});
        vis[sr][sc] = 1;
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;q.pop();
            
            ans.push_back({x,y});
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            
        }
                           
        return ans;
    }
};