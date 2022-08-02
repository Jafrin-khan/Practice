class Solution {
public:
    
    int cal(vector<vector<int>>& mat , int row , int col){
        
        int n = mat.size();
        int bound = mat[0].size();
        
        int cnt = 0;
        
        for(int i = row ; i < n ; i++){
            
            for(int j = col ; j < bound ; j++){
                
                if(mat[i][j] == 1){
                    cnt++;
                }
                
                else{
                    bound = j;
                }
            }
        }
        
        return cnt;
        
    }
    int numSubmat(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int cnt = 0;
        
         for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                
               if(mat[i][j] == 1){
                   cnt += cal(mat , i , j);
               }
            }
        }
        
        return cnt;
        
    }
};