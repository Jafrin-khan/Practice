class Solution {
public:
    
    bool f(int i , int j , string& text, string& pattern ,  vector<vector<int>>& dp){
        
        if(i < 0 && j < 0){///////////////////////////////
            return true;
        }
        
        if(i < 0 && j >= 0){///////////////////////////////
            return false;
        }
        
        if(i >= 0 && j < 0){
            
            for(int k = 0 ; k <= i ; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }
            
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(pattern[i] == text[j] || pattern[i] == '?'){
            return dp[i][j] = f(i - 1 , j - 1 , text , pattern , dp);
        }
        
        else if(pattern[i] == '*'){
            return dp[i][j] = f(i - 1 , j , text , pattern , dp) || f(i , j - 1 , text , pattern , dp);//////////////////   2nd condition //////////////////
        
        }
        
        else{
            return dp[i][j] = false;
        }
          
    }
    bool isMatch(string text, string pattern) {
        
        int n = text.size();
        int m = pattern.size();
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        
        return f(m-1 , n-1 , text , pattern , dp);
        
    }
};