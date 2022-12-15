class Solution {
public:
    
    /*
    TC = O(M*N).....every element of matrix is processed at most three times.
    
    SC = O(M*N)...Stack space in recursive call
    
    */
    
    void dfs(int i , int j , vector<vector<char>>& board){
        
        int n = board.size();
        int m = board[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O'){
            return;
        }
        
        board[i][j] = '$';
        
        dfs(i+1 , j , board);
        dfs(i , j+1 , board);
        dfs(i-1 , j , board);
        dfs(i , j-1 , board);
    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        //row-wise iterate krke 1st aur last col check kro koi 'O' h to dfs
        for(int i = 0 ; i < n ; i++){
            
            if(board[i][0] == 'O'){
                dfs(i , 0 , board);
            }
            
            if(board[i][m-1] == 'O'){
                dfs(i , m-1 , board);
            }
        }
        
         //col-wise iterate krke 1st aur last row check kro koi 'O' h to dfs
         for(int i = 0 ; i < m ; i++){
             
             if(board[0][i] == 'O'){
                 dfs(0 , i , board);
             }
             
             if(board[n-1][i] == 'O'){
                 dfs(n-1 , i , board);
             }
         }
        
        //uper do loops se humne boundary conditions check krli hai aur jo O h boundary mai aur usse connected unhe $ kr diya h dfs se to ab jo bche hue O h wo puri tarah X se surrounded h (wo Os ka patch) isliye un sbko X m convert krdo
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        //jo $ hai wo actually m Os ka patch h jo boundary se jude hai isliye surrounded by X ni h isliye unhe ab pehle jaise O bana do
        
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(board[i][j] == '$'){
                    board[i][j] = 'O';
                }
            }
        }
                
    }
};