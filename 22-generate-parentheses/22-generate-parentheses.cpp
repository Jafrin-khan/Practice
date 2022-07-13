class Solution {
public:
    
    
    void f(int open , int close ,string &s , vector<string>& ans){
        
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        
        if(open){
            
            s.push_back('(');
            f(open-1 , close , s , ans);
            s.pop_back();
            
        }
        
        if(close > open){
            
            s.push_back(')');
            f(open,close-1,s,ans);
            s.pop_back();
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        int open = n;
        int close = n;
        
        vector<string> ans;
        string s = "";
        
        f(open , close , s , ans);
        
        return ans;
    }
};