class Solution {
public:
    
    /*remember imp. trick in these type of questions...ek iske simailar common int in matrix krke ek ques h wo bhi bhaut imp h...in dono k logic*/
    
    vector<string> commonChars(vector<string>& words) {
        
       /*
       YE METHOD GFG K LIYE OPTIMUM H YHA NI ..KYU YE DRY RUN KRKE DEKHO
       unordered_map<char,int> mp;
        
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = 0 ; j < words[i].size() ; j++){
                if(mp[words[i][j]] == i){
                    mp[words[i][j]]++;
                }
            }
        }
        
        vector<string> ans;
        for(auto it : mp){
            if(it.second == words.size()){
                string s = "";
                s += it.first;
                ans.push_back(s);
            }
        }
        return ans;
        */
        
        vector<int> cnt(26,0);
        for(auto c : words[0]){
            cnt[c-'a']++;
        }
        
        for(int i = 1 ; i < words.size() ; i++){
            vector<int> v(26,0);
            
            for(auto c : words[i]){
                v[c-'a']++;
            }
            
            for(int j = 0 ; j < 26 ; j++){
                cnt[j] = min(cnt[j],v[j]);
            }
        }
        
        vector<string> ans;
        
        for(int i = 0 ; i < 26 ; i++){
            while(cnt[i]--){
                string s = "";
                s+=(i+'a');
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};