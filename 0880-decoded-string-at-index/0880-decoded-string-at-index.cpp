class Solution {
public:
    /*
    https://www.youtube.com/watch?v=6iE7QJRMXzs
    */
    
    
    string decodeAtIndex(string s, int k) {
        
        int n = s.size();
        long size = 0;
        
        //calculating the size;
        for(int i = 0 ; i < n ; i++){
            if(isdigit(s[i])) size = size*(s[i]-'0');
            else size++;
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            //in case when k goes out of bound
            k %= size;
            if((k == 0 || k == size) && !isdigit(s[i])){
                string ans = "";ans+=s[i];return ans;
            }
            else if(isdigit(s[i])) size/=(s[i]-'0');
            else size--;
        }
        
        return "";
    }
    
};