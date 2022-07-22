class Solution {
public:
    
    bool isPossible(int row , int col , char ch , vector<vector<char>>& board){
        
        int n = board.size();
        // int m = board[0].size();
        
        for(int i = 0 ; i < n ; i++){
            
            //checking row
            if(board[i][col] == ch){
                return false;
            }
            
            //checking col
            if(board[row][i] == ch){
                return false;
            }
            
            //checking boxes
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch){
                return false;
            }
        }
        
        return true;
        
    }
    
    bool solve(vector<vector<char>>& board){
         int n = board.size();
         int m = board[0].size();
        
         for(int i = 0 ; i < n ; i++){
             for(int j = 0 ; j < m ; j++){
                 
                  if(board[i][j] == '.'){
                      for(char ch = '1' ; ch <= '9' ; ch++){
                    
                         if(isPossible(i , j , ch , board)){
                             board[i][j] = ch;
                     
                         if(solve(board) == true){
                             return true;
                     }
                     
                     else{
                         board[i][j] = '.';
                        
                     }
                 }
             }
                      
            return false;
                          }
                     }
                     
         }
        
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};