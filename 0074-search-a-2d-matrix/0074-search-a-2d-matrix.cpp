class Solution {
public:
    
    // https://leetcode.com/problems/search-a-2d-matrix/discuss/1895837/C%2B%2B-BINARY-SEARCH-TREE-(**)-Explained-with-IMG
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0;
        int col = m-1;
        
        while(row < n && col >= 0){
            if(matrix[row][col] == target) return true;
            
            else if(matrix[row][col] < target) row++;
            
            else col--;
        }
       
        return false;
    }
};