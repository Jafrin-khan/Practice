class Solution {
public:
    
    void dfs(int i , int j , vector<vector<char>>& board){
        
        int m = board.size();
        int n = board[0].size();
        
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O'){
            return;
        }
        
        board[i][j] = '$';
        dfs(i-1 , j , board);
        dfs(i , j - 1 , board);
        dfs(i+1 , j , board);
        dfs(i , j+1 , board);
        
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
         for(int i = 0 ; i < m ; i++){
             if(board[i][0] == 'O'){
                 dfs(i , 0 , board);
             }
             
             if(board[i][n-1] == 'O'){
                 dfs(i , n-1 , board);
             }
         }
        
        for(int i = 0 ; i < n ; i++){
            if(board[0][i] == 'O'){
                dfs(0 , i , board);
            }
            
            if(board[m-1][i] == 'O'){
                dfs(m-1 , i , board);
            }
        }
        
         for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '$'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};