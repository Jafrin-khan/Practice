class Solution {
public:
   unordered_map <string, bool> m; // Map will work as cache or help in memoization step
    
    bool wordBreak(string s, vector <string> &d) 
    {
        if(find(d.begin(), d.end(), s) != d.end()) // we found a part hurray, return 1
            return true;
        
        if(m.find(s) != m.end()) // return precomputed value for particular s , stored in map
            return m[s];
        
        for(int i=1; i<s.length(); i++)
        {
            string left = s.substr(0, i); // check for each substring of s
            if(find(d.begin(), d.end(), left) != d.end() && wordBreak(s.substr(i), d))
            { // if that left exists in d, than check for remaining part of s via recursion
                return m[left] = true; // if both part return true , store it in map and return true
            }
        }
        return m[s] = false; // else just store false for that s in map and return false
    }
};