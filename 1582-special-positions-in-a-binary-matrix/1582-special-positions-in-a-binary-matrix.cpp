class Solution {
public:
    
    bool check(vector<vector<int>>& mat , int row , int col){
        
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0 ; i < n ; i++){
            
            if(i == row){
                continue;
            }
            if(mat[i][col] != 0){
                return false;
            }
        }
        
         for(int i = 0 ; i < m ; i++){
            
            if(i == col){
                continue;
            }
            if(mat[row][i] != 0){
                return false;
            }
        }
        
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        
        int cnt = 0;
        
         int n = mat.size();
        int m = mat[0].size();

        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(mat[i][j] == 1){
                    if(check(mat , i , j)){
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};