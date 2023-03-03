class Solution {
public:
    /*
    TC = O(N*M)
    SC = O(N*M)
    */
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dup = board;
        
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                int cell = dup[row][col];
                int live = 0;
                for(int i = -1 ; i <= 1 ; i++){
                    for(int j = -1 ; j <= 1 ; j++){
                        int nx = row + i;
                        int ny = col + j;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(nx == row && ny == col) continue;// V.imp condition baar baar bhul jaate ho
                        else{
                            if(dup[nx][ny] == 1)live++;
                        }
                    }
                }
              
                if(live < 2 && cell == 1) board[row][col] = 0;
                else if((live == 2 || live == 3) && cell == 1) board[row][col] = 1;
                else if(live > 3 && cell == 1) board[row][col] = 0;
                else if(cell == 0 && live == 3) board[row][col] = 1;  
            }
        }
    }
};