class Solution {
public:
    
    int f(int ind , string s , vector<int>& dp){
        
        if(ind > s.size()){
            return 0;
        }
        
        if(ind == s.size()){
            return 1;
        }
        
        if(s[ind] == '0'){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        string b = s.substr(ind , 2);
        
        int ways1 = f(ind + 1 , s , dp);
        int ways2 = 0;
        
        if(stoi(b) > 0 && stoi(b) <= 26){
            ways2 = f(ind + 2 , s , dp);
        }
        
        return dp[ind] = ways1 + ways2;
        
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.size(),-1);
        return f(0 , s , dp);
        
    }
};