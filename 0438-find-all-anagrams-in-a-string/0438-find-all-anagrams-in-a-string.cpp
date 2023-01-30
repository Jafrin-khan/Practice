class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int len = s.size();
        int window = p.size();
        vector<int> ans;
        
        if(len < window){
            return ans;
        }
        vector<int> vp(26,0);
        vector<int> hash(26,0);
        
        int left = 0;
        int right = 0;
        
        while(right < window){
            hash[s[right]-'a']++;
            vp[p[right]-'a']++;
            
            right++;
        }
      
        while(right < len){
            if(vp == hash){
                ans.push_back(left);
            }
            
            hash[s[right]-'a']++;
            hash[s[left]-'a']--;
            
            right++;
            left++;
        }
        
          if(vp == hash){
                ans.push_back(left);
            }
        
        return ans;
    }
};