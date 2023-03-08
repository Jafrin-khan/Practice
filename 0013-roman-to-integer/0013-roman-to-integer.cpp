class Solution {
public:
    int romanToInt(string s) {
        
//         char symbol[7] = {'I' , 'V' , 'X' , 'L' , 'C' , 'D' , 'M'};
//         int value[7] = {1 , 5 , 10 , 50 , 100 , 500 , 1000};
        
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.size();
        int ans = mp[s[n-1]];
        
        int i = n-2;
        while(i >= 0){
            if(mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
            i--;
        }
        
        return ans;
        
    }
};