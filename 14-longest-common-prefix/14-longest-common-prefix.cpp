class Solution {
public:
    
    static bool cmp(string& s1 , string& s2){
        return s1.size() < s2.size();
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin() , strs.end() , cmp);
        
        string ans = strs[0];
        
       
        for(int i = 1 ; i < strs.size() ; i++){
            
            for(int j = 0 ; j < ans.size() ; j++){
                
                if(ans[j] != strs[i][j]){
                    ans.erase(j);
                }
            }
        }
        
        return ans;
        
    }
};