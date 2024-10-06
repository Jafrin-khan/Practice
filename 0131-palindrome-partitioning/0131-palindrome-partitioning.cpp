class Solution {
public:
    
    bool isValid(int start , int end , string s){
       while(start < end){
                if(s[start] != s[end]) return false;
                start++;
                end--;
            }
        return true;
    }
    
    void f(int ind , vector<string> v , vector<vector<string>>& ans , string s){
        
        if(ind == s.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i = ind ; i < s.size() ; i++){
            if(isValid(ind , i , s)){
                v.push_back(s.substr(ind , i - ind + 1));
                f(i+1 , v , ans , s);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> helper;
        
        f(0 , helper , ans , s);
        
        return ans;
        
    }
};