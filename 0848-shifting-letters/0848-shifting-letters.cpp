/*
Let's say the vector shifts is of length M, then
S[M - 1] is shifted by shifts[M - 1]
S[M - 2] is shifted by shifts[M - 2] + shifts[M-1]
......
S[0] is shifted by shifts[0] + shifts[1] + ...... + shifts[M-2] + shifts[M - 1]
Therefore, if we start by shifting S[M - 1], decrement the index one by one, and keep track of the sum of the current shifts, we can do the shifting easily in one pass. When we deal with S[i], we first add S[i] to the accumulated shift, and then shift the character by the accumulated shift.
Using the fact that shifting 26 times is equivalent to doing nothing, we use the mod to wrap around.

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        // accumulated shift counting back from shifts.size() - 1 to the first element.
        int aggshift = 0;
        // Do the shifts, shifting 26 times is equivalent to doing nothing.
        for(int i = shifts.size() - 1; i >= 0; i--){
            aggshift += shifts[i];
            aggshift %= 26;
            S[i] = 'a' + ((S[i] - 'a') + aggshift) % 26;
        }
        return S;
    }
};
*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int suffixSum = 0;
        for(int i = n-1; i >= 0 ; i--){
            suffixSum = (suffixSum + shifts[i])%26;
            s[i] = 'a' + (s[i] - 'a' + suffixSum)%26;
        }
        
        return s;
    }
};