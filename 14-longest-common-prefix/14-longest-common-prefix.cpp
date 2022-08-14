class Solution {
public:
    
    static bool cmp(string &a , string &b){
        return a.size() < b.size();
    }
    
    string longestCommonPrefix(vector<string>& s) {
        
        sort(s.begin() , s.end() , cmp);
        string ans = s[0];
        
        for(int i = 1 ; i < s.size() ; i++){
            
            int p = 0;
            int q = 0;
            
            while(p < ans.size()){
                if(ans[p] == s[i][q]){
                    p++;
                    q++;
                }
                
                else{
                    ans.erase(p , ans.size()-p+1);
                    break;
                }
            }
        }
        
        return ans;
        
    }
};