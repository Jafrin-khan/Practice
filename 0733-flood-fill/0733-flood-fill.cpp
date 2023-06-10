class Solution {
public:
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color) return image;
        
        int n = image.size();
        int m = image[0].size();
        int c = image[sr][sc];
        
         int dx[4] = {-1 , 1 , 0 , 0};
         int dy[4] = {0 , 0 , -1 , 1};
         
         queue<pair<int,int>> q;
         
         q.push({sr,sc});
        image[sr][sc] = color;
        
         while(!q.empty()){
             
             int size = q.size();
             
             while(size--){
                 int row = q.front().first;
                 int col = q.front().second;q.pop();
               
                 for(int i = 0 ; i < 4 ; i++){
                     int nx = row + dx[i];
                     int ny = col + dy[i];
                     
                     if(nx < 0 || ny < 0 || nx >= n || ny >= m || image[nx][ny] != c) continue;
                     image[nx][ny] = color;
                     q.push({nx , ny});
                 }
             
             }
             
         }
        
        return image;
    }
};