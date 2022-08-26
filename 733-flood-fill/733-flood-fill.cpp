class Solution {
public:
    
    void f(int i , int j , vector<vector<int>>& image, int color , int newColor){
        
        int n = image.size();
        int m = image[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != color){
            return;
        }
        
        image[i][j] = newColor;
        
        f(i+1 , j , image , color , newColor);
        f(i , j+1 , image , color , newColor);
        f(i-1 , j , image , color , newColor);
        f(i , j-1 , image , color , newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        if(image[sr][sc] == color){
              return image;
          }
        
        f(sr , sc , image , image[sr][sc] , color);
        
        return image;
        
    }
};