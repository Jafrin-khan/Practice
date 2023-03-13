class Solution {
public:
    
    /*
    It's possible in O(log(mn)) which is much faster than O(m+n).
For proof, consider that log(mn) = log m + log n.
And in the domain being considered m, n >= 1 (and also the >=0 domain) the following holds truelog m < m
Therefore O(log(mn)) < O(m+n)
    */
    
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