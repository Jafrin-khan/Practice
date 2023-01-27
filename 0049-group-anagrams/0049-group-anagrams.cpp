class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(int i = 0 ; i < s.size() ; i++){
            string dup = s[i];
            sort(dup.begin() , dup.end());
            mp[dup].push_back(s[i]);    
        }
        
        for(auto it : mp) ans.push_back(it.second);
        
        return ans;
    }
};