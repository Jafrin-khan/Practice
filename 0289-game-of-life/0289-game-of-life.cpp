class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)return 0;
        return 1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();  
        // create a ans vector to store next state
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int live=0;
                
                // move in ll eight direction and count the no. of live cells
                for(int i = -1 ; i <= 1 ; i++){
                    for(int j = -1 ; j <= 1 ; j++){
                    int cx=row+i;
                    int cy=col+j;
                    if(row == cx && col == cy) continue; // inp condition baar baar bhulne ki aadat
                    if(isValid(cx,cy,n,m) && board[cx][cy]==1){
                        live++;
            
                    }
                }
                }
                // Check if current cell is live or dead and apply rules accordingly and update ans vector
                if(board[row][col]==1){
                    if(live<2 || live >3){
                        ans[row][col]=0;
                    }else{
                        ans[row][col]=1;
                    }
                }
                else{
                    if(live==3){
                        ans[row][col]=1;
                    }else{
                        ans[row][col]=0;
                    }
                }
            }
        }
        // update board to next state
        board=ans;
    }
};