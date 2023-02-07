class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s = to_string(n);
        next_permutation(s.begin(),s.end());
        
        if(s == to_string(n)) return -1;
        
        int dup = std:: stol(s);
        if(dup > n) return dup;
        else return -1;
        
    }
};