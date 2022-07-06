class Solution {
public:
    
    static bool cmp(string &a , string &b){
        return a.size() < b.size();
    }
    
    bool toCompare(string &s1 , string &s2){
        
        int n = s1.size();
        int m = s2.size();
        
        if(n != m+1){
            return false;
        }
        
        int p1 = 0;
        int p2 = 0;
        
        while(p1 < n){
            
            if(s1[p1] == s2[p2]){
                p1++;
                p2++;
            }
            
            else{
                p1++;
            }
        }
        
        if(p1 == n && p2 == m){
            return true;
        }
        
        return false;
    }
    int longestStrChain(vector<string>& words) {
      
        int n = words.size();
        vector<int> dp(n,1);
        
        sort(words.begin() , words.end() , cmp);
        int maxi = 1;
        
        for(int ind = 0 ; ind < n ; ind++){
            
            for(int prev_ind = 0 ; prev_ind < ind ; prev_ind++){
                
                if(toCompare(words[ind] , words[prev_ind]) && (dp[ind] < dp[prev_ind]+1) ){
                    dp[ind] = dp[prev_ind] + 1;
                  
                }
                
                if(dp[ind] > maxi){
                    maxi = dp[ind];
                }
                
            }
        }
        
        return maxi;   
        
        
    }
};