class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int start = 0;
        int end = 0;
        
        int maxi = INT_MIN;
        int maxCount = 0;
        
        unordered_map<char , int> mp;
        
        while(end < n){
            
            mp[s[end]]++;
            maxCount = max(maxCount , mp[s[end]]);
            
            //to check if we have flipped more than k characters then we decrease the window size
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