class Solution {
public:
    
    bool isValid(string s){
        int start = 0;
        int end = s.size()-1;
        
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void f(int ind , vector<vector<string>>& ans , vector<string> helper , string s){
        
        if(ind == s.size()){
            ans.push_back(helper);
            return;
        }
        
        for(int i = ind ; i < s.size() ; i++){
            string temp = s.substr(ind , i - ind + 1);
            if(isValid(temp)){
                helper.push_back(temp);
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