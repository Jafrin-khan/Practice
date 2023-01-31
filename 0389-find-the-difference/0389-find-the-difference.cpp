class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);
        
        for(int i = 0 ; i < s.size() ; i++){
            cnt1[s[i]-'a']++;
            
        }
        
        for(int i = 0 ; i < t.size() ; i++){
            cnt2[t[i]-'a']++;
            
        }
        char ans;
        for(int i= 0 ; i < 26 ; i++){
            if(cnt1[i] != cnt2[i]){
                ans = i+'a';
            }
        }
       
        return ans;
    }
};