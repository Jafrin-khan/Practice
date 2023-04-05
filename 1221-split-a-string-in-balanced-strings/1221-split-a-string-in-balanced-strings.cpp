class Solution {
public:
    int balancedStringSplit(string s) {
        int countl=0,countr=0,i=0,ans=0;
        while(i<s.length())
        {
            if(s[i]=='L')countl++;
            
            else if(s[i]=='R')countr++;
            
            if(countl==countr)
            {
                ans++;
                countl=0;
                countr=0;
            }
            i++;

        }
        return ans;
    }
};