class Solution {
public:
    
    /*
Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
    */
    bool isValid(char ch , int row , int col , vector<vector<char>>& board){
        
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == ch || board[i][col] == ch) return false; //checking rows and cols
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;//checking the box
        }
        
        return true;
    }
    
    bool f(vector<vector<char>>& board){
        
         for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                
                if(board[i][j] == '.'){
                for(char ch = '1' ; ch <= '9' ; ch++){
                    if(isValid(ch , i , j , board)){
                        board[i][j] = ch;
                        if(f(board)) return true;//is character k corresponding hamein ans mil gaya islie true
                        board[i][j] = '.';
                    }
                }  
                    return false;//is character k corresponding hamein ans nahi mila islie hum false return krre taaki backtrack krke dusre character ke character ki recursive call start kr ske
                }
                
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       
       f(board);
        
    }
};