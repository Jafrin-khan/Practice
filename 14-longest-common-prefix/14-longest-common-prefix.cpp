class Solution {
public:
    
    static bool cmp(string &a , string &b){
       return a.size() < b.size();
    }
    
    string longestCommonPrefix(vector<string>& s) {
        
        sort(s.begin() , s.end() , cmp);
        string ans = s[0];
        
        for(int i = 1 ; i < s.size() ; i++){
            int j = 0;
            while(j < ans.size()){
                if(s[i][j] != ans[j]){
                    ans.erase(j , ans.size() -j + 1);
                    break;
                }
                j++;
            }
        }
        
        return ans;
        
    }
};