class Solution {
public:
    
    void f(int i , int j , vector<vector<char>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1'){
            return;
        }
        
        grid[i][j] = '$';
        
        f(i+1 , j , grid);
        f(i , j+1 , grid);
        f(i , j-1 , grid);
        f(i-1 , j , grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    f(i , j , grid);
                }
            }
        }
        
        return cnt;
    }
};