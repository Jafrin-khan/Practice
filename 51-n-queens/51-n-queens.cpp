class Solution {
public:
    
     vector<vector<string>> ans;
    
    bool isSafe(int row , int col , vector<string> board){
        
           for(int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j--){
               if(board[i][j] == 'Q'){
                   return false;
               }
           }
                  
           for(int i = row , j = col ; i >= 0 && j < board[0].size() ; i-- , j++){
               if(board[i][j] == 'Q'){
                   return false;
               }
           }
                  
          for(int i = row ; i >= 0 ; i--){
              if(board[i][col] == 'Q'){
                  return false;
              }
          }
                  
         return true;
    }
                  
    void solve(int row , vector<string> board){
        
        if(row == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int i = 0 ; i < board[0].size() ; i++){
            
            if(isSafe(row , i , board)){
                board[row][i] = 'Q';
                solve(row + 1 , board);
                board[row][i] = '.';
            }
        }
    }
                  
    vector<vector<string>> solveNQueens(int n) {
        
        string s = "";
        for(int i = 0 ; i < n ; i++){
            s += ".";
        }
        vector<string> board(n , s);
        solve(0 , board);
        
        return ans;
        
        
    }
};