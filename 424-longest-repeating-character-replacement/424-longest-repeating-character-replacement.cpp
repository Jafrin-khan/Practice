class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char , int> mp;
        
        int start = 0;
        int end = 0;
        int maxCount = 0;
        int maxi = INT_MIN;
        
        while(end < s.size()){
            
            mp[s[end]]++;
            maxCount = max(maxCount , mp[s[end]]);
            
            if(end - start + 1 - maxCount > k){
                mp[s[start]]--;
                start++;
            }
            
            maxi = max(maxi , end - start + 1);
            end++;
        }
        
        return maxi;
        
    }
};