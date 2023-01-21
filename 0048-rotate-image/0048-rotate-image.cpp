class Solution {
public:
    
    /*
    TC = O(N^2)
    SC = O(1)
    */
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix.size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};