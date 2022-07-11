class Solution {
public:
    
    bool isPalindrome(int start , int end , string s){
        
        while(start <= end){
            if(s[start++] != s[end--]){
            return false;
        }
        }
        
        return true;
    }
    
    void f(int ind , string s , vector<string> h , set<vector<string>>& st){
        
        if(ind >= s.size()){
            st.insert(h);
            return;
        }
        
        for(int i = ind ; i < s.size() ; i++){
            
            if(isPalindrome(ind , i , s)){
                h.push_back(s.substr(ind , i - ind + 1));
                 f(i+1 , s , h , st);
                h.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> h ;
        set<vector<string>> st;
        
        f(0 , s , h , st);
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
    }
};