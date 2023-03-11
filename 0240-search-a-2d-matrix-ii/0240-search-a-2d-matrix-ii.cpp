class Solution {
public:
    
//Why this brute force giving TLE even for small test cases...koi bug hai ismai .....check
    
//     bool binarySearch(int left , int right ,int i, int target , vector<vector<int>>& matrix){
//         while(left < right){
//             int mid = (left+right)/2;
            
//             if(matrix[i][mid] == target) return true;
//             else if(matrix[i][mid] < target) left = mid;
//             else right = mid;
//         }
//         return false;
//     }
    
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(int i = 0 ; i < n ; i++){
//             if(matrix[i][0] <= target && binarySearch(0,m-1,i,target,matrix)) return true;
//         }
        
//         return false;
//     }
    
    /*
    TC = 
    SC = 
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0;
        int col = m-1;
        
        while(row < n && col >= 0){
            //target found
            if(matrix[row][col] == target) return true;
            
            //hr row ka last element check krre hai agr wo chotu hai to saaf hai k row increase krna hoga
            else if(matrix[row][col] < target) row++;
            //else agr bada h to mtlb col ko adjust krna hoga col-- krke
            else col--;
            
        }
        return false;
    }
  
};