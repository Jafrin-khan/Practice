/*
Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O

(N! * N) nearly.

Space Complexity: O(N)
*/

class Solution {
public:
    
    bool isValid(vector<string> chess , int i , int j){
        
        for(int row = i-1 ; row >= 0 ; row--){
            if(chess[row][j] == 'Q') return false; 
        }
        
        for(int row = i - 1 , col = j - 1 ; row >= 0 && col >= 0 ; row-- , col--){
            if(chess[row][col] == 'Q') return false;
        }
        
        for(int row = i - 1 , col = j + 1 ; row >= 0 && col < chess[0].size() ; row-- , col++){
            if(chess[row][col] == 'Q') return false;
        }
        
        return true;
    }
    
    void play(int row , vector<string>& chess , vector<vector<string>>& ans){
        if(row == chess.size()){
            ans.push_back(chess);
            return;
        }
        
        for(int col = 0 ; col < chess[0].size() ; col++){
            if(isValid(chess , row , col)){
                chess[row][col] = 'Q';
                play(row+1 , chess , ans);
                chess[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        string s = "";
        for(int i = 0 ; i < n ; i++){
            s += ".";
        }
        
        vector<string> chess(n , s);
        play(0 , chess , ans);
        
        return ans;
    }
};