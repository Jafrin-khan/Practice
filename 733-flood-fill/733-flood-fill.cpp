class Solution {
public:
    
    int dx[4] = {0 , 0 , -1 , 1};
    int dy[4] = {-1 , 1 , 0 , 0};
        
    void dfs(int row , int col , int color,vector<vector<int>>& image ,int newColor){
        
        image[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == color){
                dfs(nr , nc , color , image , newColor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
       if(image[sr][sc] != newColor){ 
       dfs(sr , sc , image[sr][sc] , image , newColor);
       }
       return image;
        
        
    }
};