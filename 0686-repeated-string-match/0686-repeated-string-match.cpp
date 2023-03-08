/*
The question need deep analysis , S(final string ) = A+A+A ....... .
Logic: Keep concatinating A's with S untill S.length()>=B.length() , only then there is possiblity of B to be it's subtring as it is obvious that a string can never be a substring of another string if other string is smaller than it.
Now check is B is substring of S using find() , if yes then return count A. (count is a variable which keep track of how many times A is repeated)
But if not , concatinate S with A one for time and check for chance of B as it's substring for last time ... this time if you find that B is not substring of S, then return -1 i.e there is no way repeating A any number of times, B becomes Substring of S.

Confusion : Here is still a point of confusion , why i have appended one more time. Observe carefully that the first charater of B must be in the S from (0-a.size()-1) index . eg . A= abc and B = cabcabc , So B[0] which is c must be in S (S=ab cabcab c ) . The point lies in the fact that your S is just >= B.size() and B[0] lies at the S[A.size()-1] , now B will not fit in the string S(A.size()-1 -> S.size()-1).. So you need to append S one more time with A .
This example will help u clear all this ..
Suppose A = aaaaab and B = ba
Now S = A (1 time) is already >= B.size()
So we do not need to append S with A , we will directly check if "ba" is in the S or not which is not ..
So we will append S one last time with A , Now S becomes , S = aaaaabaaaaab , again searching for B in the S will get you with solution ..

 int repeatedStringMatch(string A, string B) {
        string s="";
        int count = 0;
        while(s.size()<B.size())
        {
            s+=A;
            count++;
        }
        if(s.find(B)!=string::npos)
            return count;
        s+=A;
        count++;
        if(s.find(B)!=string::npos)
            return count;
        
        return -1;
    }
};
*/
/*********************************************************************IMP*******************************************************/
//Do by KMP and Rabin Karp algorithm as well......V.imp

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string copy = a;
        int cnt = 1;
         while(a.size() < b.size()){
             a += copy;
             cnt++;
         }
         
         if(a.find(b) != -1) return cnt;
         a += copy;
         cnt++;
        
         if(a.find(b) != -1) return cnt;
        
         return -1;
         
    }
};