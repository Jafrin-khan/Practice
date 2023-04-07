class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string , char> mp;
        vector<int> vis(26,0);
        
        string word = "";
        int ind = 0;
        
        for(int i = 0 ; i <= s.size() ; i++){
            if(i == s.size() || s[i] == ' '){
               //cout<<mp[word]<<" "<<pattern[ind]<<endl;
                
                if(mp.find(word) == mp.end()){ 
                    if(!vis[pattern[ind] - 'a']){
                        mp[word] = pattern[ind] , vis[pattern[ind] - 'a'] = 1;
                    }
                    else return false;
                }
                    
                else if(mp[word] != pattern[ind]) return false;
                
                word = "";
                ind++;
            }
            else word += s[i];
        }
        
        
        if(ind != pattern.size()) return false;
       
        return true;
        
    }
};