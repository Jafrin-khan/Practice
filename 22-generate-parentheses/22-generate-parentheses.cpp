class Solution {
public:
    
    void f(int open , int close , vector<string>& ans , string s){
        
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        
        if(open){
            f(open - 1 , close , ans , s + '(');
        }
        
        if(close > open){
            f(open , close-1 , ans , s + ')');
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        
        f(n , n , ans , "");
        
        return ans;
        
    }
};