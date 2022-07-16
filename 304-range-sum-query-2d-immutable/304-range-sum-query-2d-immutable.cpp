class NumMatrix {
public:
    
    //https://www.youtube.com/watch?v=rkLDDxOcJxU
    
    //use prefix sum property
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        //prefix sum of cols
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        
        //prefix sum of rows
         for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mat[i][j] += mat[i-1][j];
            }
        }
        
        matrix = mat;
      
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int totSum = matrix[row2][col2];
        int extra = -(row1 != 0 && col1 != 0 ? matrix[row1-1][col1-1] : 0) + 
                    (row1 == 0 ? 0 : matrix[row1-1][col2]) +
                    (col1 == 0 ? 0 : matrix[row2][col1-1]);
        
        return totSum - extra;
            
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */