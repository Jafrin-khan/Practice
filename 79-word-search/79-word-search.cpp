class Solution {
public:
    
    bool f(int i , int j , int ind , vector<vector<char>>& board, string word){
        
         int n = board.size();
        int m = board[0].size();
        
        if(ind >= word.size()){
            return true;
        }
        
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[ind]){
            return false;
        }
        
        char ch = board[i][j];
        board[i][j] = '$';
        
        bool ans =  f(i+1 , j , ind+1 , board , word) ||
                f(i , j+1 , ind+1 , board , word) ||
                f(i-1 , j , ind+1 , board , word) ||
                f(i , j-1 , ind+1 , board , word);
        
        board[i][j] = ch;
        
        return ans;
     
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                
                if(board[i][j] == word[0] && f(i , j , 0 , board , word)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};