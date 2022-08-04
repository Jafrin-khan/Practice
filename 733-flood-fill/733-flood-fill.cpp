class Solution {
public:
    
    void f(int i , int j ,int prevCol , int color , vector<vector<int>>& image){
        
        int n = image.size();
        int m = image[0].size(); 
        
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != prevCol){
            return;
        }
        
        image[i][j] = color;
        
        f(i+1 , j , prevCol , color , image);
        f(i , j+1 , prevCol , color , image);
        f(i-1 , j , prevCol , color , image);
        f(i , j-1 , prevCol , color , image);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         
        if(image[sr][sc] != color){
            f(sr , sc , image[sr][sc] , color , image);
        }
        
        return image;
        
    }
}; 