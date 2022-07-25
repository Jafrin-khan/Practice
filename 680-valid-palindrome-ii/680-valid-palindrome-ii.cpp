class Solution {
public:
    
    bool validPalindrome(string s) {
        
        int s1 = 0;
        int e1 = s.size()-1;
        
        int t = 0;
        
        while(s1 < e1){
            
            if(s[s1] == s[e1]){
                s1++;
                e1--;
            }
            
            else{
                t++;
                s1++;
            }
        }
        
        if(t <= 1){
            return true;
        }
        
        s1 = 0;
        e1 = s.size()-1;
        t = 0;
          while(s1 < e1){
            
            if(s[s1] == s[e1]){
                s1++;
                e1--;
            }
            
            else{
                t++;
                e1--;
            }
        }
        
        if(t <= 1){
            return true;
        }
        
        return false;
    }
};