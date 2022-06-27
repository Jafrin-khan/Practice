class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        unordered_map<string,vector<string>> mp;
        
        for(auto x : strs){
            
            string chars = x;
            sort(x.begin(),x.end());
            mp[x].push_back(chars);
        }
        
         vector<vector<string>> ans;
        
        for(auto x : mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};