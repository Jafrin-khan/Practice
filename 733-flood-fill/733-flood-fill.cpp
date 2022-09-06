class Solution {
public:
    
    
    void f(int i , int j , int oldColor , int newColor , vector<vector<int>>& image){
        
        int n = image.size();
        int m = image[0].size();
        
        if(i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor){
            return;
        }
        
        image[i][j] = newColor;
        
        f(i+1 , j , oldColor , newColor , image);
        f(i-1 , j , oldColor , newColor , image);
        f( i, j+1 , oldColor , newColor , image);
        f(i , j-1 , oldColor , newColor , image);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image.size() == 0){
            return image;
        }
        
        if(image[sr][sc] == color){
              return image;
          }
        
        f(sr , sc ,image[sr][sc] , color , image);
        
        return image;
        
    }
};