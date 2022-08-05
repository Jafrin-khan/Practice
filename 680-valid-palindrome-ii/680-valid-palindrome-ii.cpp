class Solution {
public:
    bool validPalindrome(string str) {
        
        int s = 0;
        int e = str.size()-1;
        
        int t = 0;
        
        while(s <= e){
            
            if(str[s] == str[e]){
                s++;
                e--;
            }
            
            else{
                s++;
                t++;
            }
            
        }
        
        if(t <= 1){
            return true;
        }
        
        s = 0;
        e = str.size()-1;
        t = 0;
        
        
         while(s <= e){
            
            if(str[s] == str[e]){
                s++;
                e--;
            }
            
            else{
                e--;
                t++;
            }
            
        }
        
        if(t <= 1){
            return true;
        }
        
        return false;
        
        
    }
};