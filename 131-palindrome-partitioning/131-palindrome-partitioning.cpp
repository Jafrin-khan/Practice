class Solution {
public:
    
    bool isValid(int start , int end , string s){
        
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        
        return true;
    }
    
    void f(int ind , vector<vector<string>>& ans , vector<string> helper , string s){
        
        if(ind == s.size()){
            if(helper.size() > 0){
            ans.push_back(helper);
            }
            return;
        }
        
        for(int i = ind ; i < s.size() ; i++){
            
            if(isValid(ind , i , s)){
                helper.push_back(s.substr(ind , i - ind + 1));
                f(i+1 , ans , helper , s);
                helper.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> helper;
        f(0 , ans , helper , s);
        
        return ans;
        
    }
};