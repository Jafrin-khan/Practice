class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size();
        
        int i = 0;
        while(i < n && (s[i] == ' ')){i++;}
        
        int flag = 0;
        if(s[i] == '-'){
            flag = 1;
            i++;
        }
        
        else if(s[i] == '+') i++;
        
        long long ans = 0;
        while(i < n && s[i] != ' '){
            if(s[i] >= '0' && s[i] <= '9'){
                ans = ans*10 + (s[i] - '0'); 
                if(ans >= INT_MAX) break;
            } 
            else break;
            
            
            i++;
        }
        
        if(flag) ans = ans*(-1);
        if(ans <= INT_MIN) return INT_MIN;
        else if(ans >= INT_MAX) return INT_MAX;
        
        return ans;
        
    }
};