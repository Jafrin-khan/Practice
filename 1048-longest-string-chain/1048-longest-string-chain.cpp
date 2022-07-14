class Solution {
public:
    
    static bool cmp(string& v1 , string& v2){
        return v1.size() < v2.size();
    }
    
    bool compare(string& s1 , string& s2){
        
        int n = s1.size();
        int m = s2.size();
        
        if(n != m-1){
            return false;
        }
        
        int p1 = 0;
        int p2 = 0;
        
        while(p2 < m){
            
            if(s1[p1] == s2[p2]){
                p1++;
                p2++;
            }
            
            else{
                p2++;
            }
        }
        
        if(p1 == n && p2 == m){
            return true;
        }
        
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin() , words.end() , cmp);
        int n = words.size();
        
        vector<int> dp(n , 1);
        int maxi = 1;
        
        for(int ind = 0 ; ind < n ; ind++){
            
            for(int prev_ind = 0 ; prev_ind < ind ; prev_ind++){
                
                if(compare(words[prev_ind] , words[ind]) && dp[ind] < dp[prev_ind] + 1){
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