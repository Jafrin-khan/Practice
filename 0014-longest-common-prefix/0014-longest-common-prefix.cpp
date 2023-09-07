class Solution {
public:

    bool static cmp(string &s1 , string& s2){
        return s1.size() < s2.size();
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        
        sort(strs.begin() , strs.end() , cmp);
        string ans = strs[0];
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < ans.size() ; j++){
                if(ans[j] != strs[i][j]){
                    ans = ans.substr(0,j);
                    break;
                }
            }
        }
        
        return ans;
        
    }
};