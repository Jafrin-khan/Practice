class Solution {
public:
    /*
    TC = O(N) + O(M)
    SC = O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            int left = matrix[i][0];
            int right = matrix[i][m-1];
            
            if(target >= left && target <= right){
                for(int j = 0 ; j < m ; j++){
                    if(matrix[i][j] == target) return true;
                }
            }
        }
        return false;
    }
};