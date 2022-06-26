class Solution {
public:
    
    static bool cmp(string &s1 , string &s2){
        return s1.size() < s2.size();
    }
    
    bool toCompare(string &s1 , string &s2){
        
        int n = s1.size();
        int m = s2.size();
        
        if(n != m+1){
            return false;
        }
        
        int p1 = 0;
        int p2 = 0;
        
        while(p1 < n ){
            
            if(s1[p1] == s2[p2]){
                p1++;
                p2++;
            }
            
            else{
                p1++;
            }
        }
        
       if(p1 == s1.size() && p2 == s2.size()){
           return true;
       }
        
        return false;
    }
    int longestStrChain(vector<string>& word) {
        
        int n = word.size();
        sort(word.begin() , word.end() , cmp);
        
        vector<int> dp(n,1);
        int maxi = 1;
        
        for(int i = 0 ; i < n ; i++){
            
            
            for(int prev = 0 ; prev < i ; prev++){
                
            if(toCompare(word[i],word[prev]) && dp[i] < dp[prev] + 1){
                dp[i] = dp[prev] + 1;
            }
        }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        
        return maxi;
    }
};