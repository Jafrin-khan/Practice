class Solution {
public:
    
    bool f(string s, vector<string>& wordDict ,  unordered_map<string , bool>& dp){
        
        if(find(wordDict.begin() , wordDict.end() , s) != wordDict.end()){
            return true;
        }
        
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        
        if(s.size() == 0){
            return false;
        }
        for(int i = 1 ; i < s.size() ; i++){
            string temp = s.substr(0 , i);
            
            if(find(wordDict.begin() , wordDict.end() , temp) != wordDict.end() && f(s.substr(i) , wordDict , dp)){
                return dp[s] = true;
            }
        }
        
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string , bool> dp;
        return f(s , wordDict , dp);
        
        
    }
};