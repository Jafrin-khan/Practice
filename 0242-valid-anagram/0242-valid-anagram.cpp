class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        for(int i = 0 ; i < s.size() ; i++){
            v1[s[i]-'a']++;
            v2[t[i]-'a']++;
        }
        return v1 == v2;
    }
};