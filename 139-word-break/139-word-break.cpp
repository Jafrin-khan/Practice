class Solution {
public:
    
    bool f(string s, vector<string>& d , unordered_map<string,bool>& dp){
            
        if(find(d.begin() , d.end() , s) != d.end()){
            return true;
        }
        
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        
        for(int i = 1 ; i < s.size() ; i++){
            
             string temp = s.substr(0,i);
             if(find(d.begin() , d.end(),temp) != d.end() && f(s.substr(i) , d , dp)){
                 return dp[s] =  true;
             }
            
            
        }
        
         return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& d) {
        
        //here we have done memoization using map
        unordered_map<string,bool> dp;
        return f(s , d , dp);
        
    }
};