class Solution {
public:
    ///Extra space is not required use more optimised approach
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0) q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;q.pop();
            
            for(int row = 0 ; row < n ; row++){
                matrix[row][y] = 0;
            }
            
            for(int col = 0 ; col < m ; col++){
                    matrix[x][col] = 0;
                }
        }
    }
};