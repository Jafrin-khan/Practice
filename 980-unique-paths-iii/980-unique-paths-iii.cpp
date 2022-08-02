class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& grid){
        
         int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1){
            return 0;
        }
        
        if(grid[i][j] == 2){
            
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(grid[i][j] == 0){
                        return 0;
                    }
                }
            }
            
            return 1;
        }
        
        grid[i][j] = -1;
        int ans = f(i+1 , j , grid) + f(i , j+1 , grid) + f(i-1 , j , grid) + f(i , j-1 , grid);
        grid[i][j] = 0;
        
        return ans;
    
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    cnt = f(i , j , grid);
                }
            }
        }
        
        return cnt;
        
    }
};