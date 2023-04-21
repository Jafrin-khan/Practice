class Solution {
public:
    //03/09/2023 ka submission consider karo revise k lie
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> row , col;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(auto i : row){
            for(int j = 0 ; j < m ; j++) matrix[i][j] = 0;
        }
        
        for(auto j : col){
            for(int i = 0 ; i < n ; i++) matrix[i][j] = 0;
        }
    }
};