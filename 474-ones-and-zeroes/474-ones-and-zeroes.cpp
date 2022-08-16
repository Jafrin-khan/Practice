class Solution {
public:
    pair<int,int> cnt01(string num){
        
        int z = 0;
        int o = 0;
        
        for(int i = 0 ; i < num.size() ; i++){
             
            if(num[i] == '0'){
                z++;
            }
            
            else{
                o++;
            }
        }
        
        return {z,o};
        
    }
    
    int f(int ind , vector<string>& s, int m, int n , vector<vector<vector<int>>>& dp){
        
        if(ind < 0){
            return 0;
        }
        
        if(dp[ind][m][n] != -1){
            return dp[ind][m][n];
        }
        
        int notTaken = 0 + f(ind - 1 , s , m , n , dp);
        pair<int,int> cnt = cnt01(s[ind]);
        int take = 0;
        
        if(cnt.first <= m && cnt.second <= n){
            take = 1 + f(ind-1 , s , m-cnt.first , n-cnt.second , dp);
        }
        
        return dp[ind][m][n] = max(take , notTaken);
        
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        int size =  s.size();
        vector<vector<vector<int>>> dp(size , vector<vector<int>>(m+1 , vector<int>(n+1,-1)));
        
        return f(size-1, s , m , n , dp);
    }
};