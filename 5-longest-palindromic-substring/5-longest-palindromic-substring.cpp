class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int n = s.size();
        int start = 0;
        int end = 1;
 
            
            for(int i = 0; i < n ; i++){
                
                int l = i-1;
                int r = i+1;
                
                while(l >= 0 && r < n && s[l] == s[r]){
                    
                    if(r-l+1 > end){
                    start = l;
                    end = r-l+1; 
                    }  
                    l--;
                    r++;
                }
            }
        
        
        
            
            for(int i = 0 ; i < n ; i++){
                
                int l = i-1;
                int r = i;
                
                while(l >= 0 && r < n && s[l] == s[r]){
                    
                    if(r-l+1 > end){
                    start = l;
                    end = r-l+1;
                    }
                    l--;
                    r++;
                }
                
                
            }
        
        
        string ans = "";
        int len = end;
        
        return s.substr(start , len);
    }
};