class Solution {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
    
    int scoreOfParentheses(string s) {
        
        int score = 0;
        char lastChar = '(';
        int n = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                n++;
            }
            
            else{
                n--;
                if(lastChar == '('){
                    score = score + pow(2,n);
                }
            }
            
            lastChar = s[i];
        }
        
        return score;
        
    }
};