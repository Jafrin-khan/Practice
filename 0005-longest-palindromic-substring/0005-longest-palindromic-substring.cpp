class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        int start = 0;
        int end = 0;
        
        int len = 1;
        
        //odd palindrome
        for(int i = 1 ; i < n ; i++){
            int l = i-1;
            int r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > len){
                start = l;
                end = r;
                len = max(len , end-start+1);
                }
                l-- ; r++;
            }   
        }
        
        //even palindrome
        for(int i = 1 ; i < n ; i++){
            int l = i-1;
            int r = i;///////////////////////////////////////////
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > len){
                start = l;
                end = r;
                len = max(len , end-start+1);
                }
                l-- ; r++;
            }   
        }
        
        string ans = "";
        for(int i = start ; i <= end ; i++){
            ans += s[i];
        }
        
        return ans;
    }
};