/*
Approach
To explain with an example:
let string be

"abcabc"
so if we concatenate(add same string) it it becomes:

"abcabcabcabc"
If we remove 1st and last charater from this string:

"bcabcabcab"
And now if we check for the original string in this and find it then the ans is true else false
As we can see in the below line there is original string at the middle:

"bc abcabc ab"
Then the output is TRUE.

Code
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s+s;
        if(t.substr(1,t.size()-2).find(s)!=-1)
            return true;
        return false;
    }
};
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
           string copy = s + s;
           copy = copy.substr(1 , copy.size()-2);
        
           if(copy.find(s) != -1) return true;
           return false;
    }
};