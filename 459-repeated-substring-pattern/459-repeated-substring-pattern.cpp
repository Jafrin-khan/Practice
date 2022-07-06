class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string dup = s + s;
        dup.erase(0,1);
        dup.erase(dup.size()-1 , 1);
      
        if(dup.find(s) != -1){
            return true;
        }
        
        return false;
    }
};