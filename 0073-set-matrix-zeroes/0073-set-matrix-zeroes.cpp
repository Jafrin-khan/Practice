class Solution {
public:
  
    //**************************https://leetcode.com/problems/set-matrix-zeroes/discuss/2525398/All-approaches-from-brute-force-to-optimal-with-easy-explanation*****************************//
    
    //1st approach..prev submission
    /* 2nd approach
     vector<int> row;
        vector<int> col;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(auto x : row){
            
            for(int i = 0 ; i < m ; i++){
                
                matrix[x][i] = 0;
                
            }
        }
        
        
        for(auto x : col){
            
            for(int i = 0 ; i < n ; i++){
                matrix[i][x] = 0;
            }
        }
    
    */
    
    //optimised approach
    void setZeroes(vector<vector<int>>& matrix) {
        
       int n = matrix.size();
       int m = matrix[0].size();
        
       bool isRow0 = false , isCol0 = false;
          for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                isRow0=true;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                isCol0=true;
                break;
            }
        }
        
       
       for(int i = 1 ; i < n ; i++){
           for(int j = 1 ; j < m ; j++){
               if(matrix[i][j] == 0){
                   matrix[0][j] = 0;
                   matrix[i][0] = 0;
               }
           }
       }
        
        for(int i = 1 ; i < n ; i++){
           for(int j = 1 ; j < m ; j++){
               if(matrix[0][j] == 0 || matrix[i][0] == 0){
                   matrix[i][j] = 0;
               }
           }
       }
        
       if(isRow0){
           for(int j = 0 ; j < m ; j++) matrix[0][j] = 0;
       }
        
      if(isCol0){
          for(int i = 0 ; i < n ; i++) matrix[i][0] = 0;
      }
     
             
    }
};