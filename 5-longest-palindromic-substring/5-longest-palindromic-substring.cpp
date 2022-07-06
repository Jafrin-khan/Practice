class Solution {
public:
    string longestPalindrome(string s) {
        
        int start = 0;
        int end = 1;
        
        int l;
        int h;
        
        //odd len
        for(int i = 0 ; i < s.size() ; i++){
            
             l = i-1;
             h = i+1;
            
            while(l >= 0 && h < s.size() && s[l] == s[h]){
                
                if((h-l+1) > end){
                    start = l;
                    end = h-l+1;
                }
                
                l--;
                h++;
            }
        }
        
        //even len
        for(int i = 0 ; i < s.size() ; i++){
            l = i-1;
            h = i;
            
            while(l >= 0 && h < s.size() && s[l]== s[h]){
                if(h-l+1 > end){
                    start = l;
                    end = h-l+1;
                }
                
                l--;
                h++;
            }
        }
        
        string ans = "";
        int len = start + end;
        
        for(int i = start ; i < len ; i++){
            ans += s[i];
        }
        
        return ans;
    }
};