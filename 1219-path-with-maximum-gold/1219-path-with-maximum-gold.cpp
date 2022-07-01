class Solution {
public:
    
     int f(int i , int j ,vector<vector<int>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        int store = grid[i][j];
        grid[i][j] = 0;
        int ans;
        
        ans = store + max({f(i+1,j , grid) , f(i,j+1,grid) , f(i-1,j,grid) , f(i,j-1,grid)});
        grid[i][j] = store;
        
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans , f(i,j,grid));
            }
        }
        
        return ans;
        
    }
};