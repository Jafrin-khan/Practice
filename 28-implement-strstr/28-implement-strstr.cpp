class Solution {
public:
    int strStr(string s, string t) {
        
     
        int i = 0;
        
        int n = s.size();
        int m = t.size();
        
        while(i < n){
             int p = i;
             int q = 0;
        if(s[p] == t[q]){
            while(p <= n){
                
               
                if(q == m){
                    return i;
                }
                
                if(s[p] == t[q]){
                    p++;
                    q++;
                }
                
                else{
                    break;
                }   
            }  }
            
            i++;
        }
        
        return -1;
    }
};