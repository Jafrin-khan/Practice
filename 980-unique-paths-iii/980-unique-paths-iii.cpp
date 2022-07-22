class Solution {
public:
    
    int f(int i , int j ,vector<vector<int>> grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1 || grid[i][j] == 1){
            return 0;
        }
        
        if(grid[i][j] == 2){
            
            int cnt = 0;
            for(int p = 0 ; p < n ; p++){
                for(int q = 0 ; q < m ; q++){
                    if(grid[p][q] == 0){
                        cnt++;
                    }
                }
            }
            
            if(cnt != 0){
                return 0;
            }
            
            return 1;
        }
        
        grid[i][j] = 1;
        
        int u = f(i - 1 , j , grid);
        int d = f(i + 1 , j , grid);
        int l = f(i , j - 1 , grid);
        int r = f(i , j + 1 , grid);
        
        return u + d + l + r;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans;
        
         for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(grid[i][j] == 1){
                        ans = f(i+1 , j , grid) + f(i-1 , j , grid) + f(i , j-1 , grid) + f(i , j+1 , grid);
                        break;
                    }
                }
            }
        
        return ans;
    }
};