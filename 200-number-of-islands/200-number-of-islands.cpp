class Solution {
public:
    
      void dfs(int i , int j ,vector<vector<char>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '2' || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '2';
        
        dfs(i-1 , j , grid);
        dfs(i , j -1 , grid);
        dfs(i+1 , j , grid);
        dfs(i , j+1 , grid);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
              int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == '1'){
                    dfs(i , j , grid);
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};