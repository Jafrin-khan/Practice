class Solution {
public:
    
    static bool cmp(string &a , string &b){
        return a.size() < b.size();
    }
    string longestCommonPrefix(vector<string>& s) {
        
      
      
        
       sort(s.begin() , s.end() , cmp);
       string ans = s[0];
       
       
       for(int i = 0; i < s.size() ; i++){
           
           for(int j = 0 ; j < ans.size() ; j++){
               
               if(ans[j] != s[i][j]){
                   ans.erase(j , ans.size()-j+1);
               }
           }          
       }
        return ans;    
        
    }
};