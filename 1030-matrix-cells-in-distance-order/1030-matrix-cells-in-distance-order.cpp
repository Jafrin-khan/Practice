class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int n, int m, int sr, int sc) {
        
        vector<vector<int>> ans;
        vector<vector<int>> vis(n , vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>> q;//<steps , <i,j>>
        q.push({0 , {sr , sc}});
        vis[sr][sc] = 1;
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!q.empty()){
            int steps = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;q.pop();
            
            ans.push_back({x,y});
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({steps+1 , {nx,ny}});
                }
            }
            
        }
                           
        return ans;
    }
};