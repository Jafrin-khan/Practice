class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        unordered_map<string , vector<string>> mp;
        
        for(auto x : s){
            
            string dup = x;
            sort(dup.begin() , dup.end());
            mp[dup].push_back(x); 
        }
        
        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};