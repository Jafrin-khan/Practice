class Solution {
public:
    /*
    BFS
    TC = O(N*M)
    SC = O(N*M)
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color) return image;
        
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 ,-1 , 1};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;q.pop();
                
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(image[nx][ny] == oldColor){
                        q.push({nx,ny});
                        image[nx][ny] = color;
                    }
                }
            }
        }
        
        return image;
    }
};