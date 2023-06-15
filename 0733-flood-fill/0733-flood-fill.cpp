class Solution {
public:
    
    //dfs
    
    void dfs(int i , int j , vector<vector<int>>& image , int n , int m , int color , int prevCol){
        
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != prevCol) return;
       
        image[i][j] = color;
        dfs(i+1 , j , image , n , m ,color , prevCol);
        dfs(i,j+1 , image , n , m ,color , prevCol);
        dfs(i-1 , j , image , n , m , color ,prevCol);
        dfs(i,j-1 , image , n , m ,color , prevCol);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color) return image;
        int prevCol = image[sr][sc];
        
        dfs(sr , sc , image , image.size() , image[0].size() , color , prevCol);
        
        return image;
    }
};