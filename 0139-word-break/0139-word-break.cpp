class Solution {
public:
    
    /*
    //Recursion
    //TC =  O(2^N)
    //SC =  O(N)
    bool f(string s,vector<string>& wordDict){
        if(find(wordDict.begin() , wordDict.end() , s) != wordDict.end()) return true;
        if(s.size() == 0) return false;
        
        for(int i = 1 ; i < s.size() ; i++){
            string temp = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end() && f(s.substr(i),wordDict)) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return f(s,wordDict);
    }
    */
    
    
    //Memoised
    //TC = O(N^3)
    //SC = O(N) + O(KL) where k is the number of words in dictionary and L is the average length of a word
    bool f(string s,vector<string>& wordDict,unordered_map<string , int>& dp){
        if(find(wordDict.begin() , wordDict.end() , s) != wordDict.end()) return true;
        if(s.size() == 0) return false;
        
        if(dp.find(s) != dp.end()) return dp[s];//////Remember this step very imp////////////
        
        for(int i = 1 ; i < s.size() ; i++){
            string temp = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end() && f(s.substr(i),wordDict,dp)) return dp[s] = true;
        }
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int> dp;
        return f(s,wordDict,dp);
    }
};