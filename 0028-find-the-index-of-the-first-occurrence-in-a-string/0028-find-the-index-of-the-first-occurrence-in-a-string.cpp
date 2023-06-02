class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        int i = 0 ; int n = needle.size();
        if(haystack.size() < n) return -1; 
        
        while(i <= haystack.size() - n){
            if(haystack[i] == needle[0]){
                if(haystack.substr(i,n) == needle) return i;
            }
            i++;
        }
        return -1;
    }
};