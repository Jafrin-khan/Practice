class Solution {
public:
    
    int dx[4] = {-1 , 0 , 1, 0};
    int dy[4] = {0 , 1 , 0 , -1};
    
    bool f(int i , int j , string s , string word , vector<vector<char>>& board , vector<vector<int>>& visited , int n , int m , int ind){
        
        if(ind == word.size()) return true;
        if(i < 0 || j < 0 || i >= n || j >= m ||  visited[i][j] || board[i][j] != word[ind]) return false;
        
      
        visited[i][j] = 1;
        bool ans = false;
        
        for(int d = 0 ; d < 4 ; d++){
            ans = ans || f(dx[d] + i , j + dy[d] , s , word , board , visited , n , m ,ind+1);
        }
        
        visited[i][j] = 0;
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> visited(n , vector<int>(m , 0));
        
        bool ans = false;
        int gotAns = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(word[0] == board[i][j]) {
                    if(f(i , j , "" , word , board , visited , n , m ,  0)) return true;
            }   
            }
        }
        return false;
    }
};