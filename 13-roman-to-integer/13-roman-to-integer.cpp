class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char , int> mp;
        
        mp['M'] = 1000;
        mp['D'] = 500;
        mp['C'] = 100;
        mp['L'] = 50;
        mp['X'] = 10;
        mp['V'] = 5;
        mp['I'] = 1;
        
        int ans = mp[s[s.size()-1]];
        
        for(int i = s.size()-1 ; i > 0 ; i--){
            
            if(mp[s[i]] > mp[s[i-1]]){
                  ans -= mp[s[i-1]];
               
            }
            
            else{
               ans += mp[s[i-1]];
            }
        }
        
        return ans;
        
    }
};