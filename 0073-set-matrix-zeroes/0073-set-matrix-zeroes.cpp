class Solution {
public:
  
    /*
    1 1 1
    1 0 1
    1 1 1
    
    r = 1
    c = 1
        
    {0,1} {2,1} m changing and n constant
    {1,0} {1,2} n  changing and m constant
    */
    
    
    
//     1 1 1
//     1 0 1
//     1 1 1
        
//     (1,1)
        
//     1,0 1,1 1,2
//     0,1 1,1 2,1
    

    void setZeroes(vector<vector<int>>& grid) {
        
        /* BRUTE */
//         int r = grid.size();
//         int c = grid[0].size();
        
//         for(int i = 0 ; i < r ; i++){
//             for(int j = 0 ; j < c ; j++){
                
//                 if(grid[i][j] == 0){
//                     //r constant
//                     for(int p = 0 ; p < c ; p++) grid[i][p] = -1;
//                     //c constant
//                     for(int q = 0 ; q < r ; q++) grid[q][j] = -1;
//                 }
//             }
//         }
        
//         for(int i = 0 ; i < r ; i++){
//             for(int j = 0 ; j < c ; j++){
//                 if(grid[i][j] == -1)  grid[i][j] = 0;
//             }
//         }
        
        /*Better*/
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> row;
        vector<int> col;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(auto it : row){
            for(int i = 0 ; i < m ; i++) grid[it][i] = 0;
        }
        
        for(auto it : col){
            for(int i = 0 ; i < n ; i++) grid[i][it] = 0;
        }
        
    }
}; 