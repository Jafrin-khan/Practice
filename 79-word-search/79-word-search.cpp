class Solution {
public:
    
    bool f(int i , int j ,vector<vector<char>>& board , string word, int ind){
        int n = board.size();
        int m = board[0].size();
         if(ind == word.size()){
            return true;
        }
        
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[ind]){
            return false;
        }
        
       
       board[i][j] = '$';
        bool ans =  f(i+1 , j , board , word , ind+1) || f(i , j+1 , board , word , ind+1)
                    || f(i-1 , j , board , word , ind+1) || f(i , j-1 , board , word , ind+1);
       board[i][j] = word[ind];
       
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int ind = 0;
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0] && f(i , j , board , word , 0)){
                    return true ;
                }
                
            }
        }
        
        return false;
    }
};