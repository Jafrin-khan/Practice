class Solution {
public:
     vector<vector<string>> ans;
    
    bool isPalindrome(int start , int end , string s){
        
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
        } 
        return true;
    }
    void f(int ind , string s , vector<string> helper){
        
        if(ind == s.size()){
            ans.push_back(helper);
            return;
        }
        
        for(int i = ind ; i < s.size() ; i++){
            
            if(isPalindrome(ind , i , s)){
                helper.push_back(s.substr(ind , i-ind+1));
                f(i+1,s,helper);
                helper.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> helper;
        f(0 , s , helper);
        
        return ans;
    }
};