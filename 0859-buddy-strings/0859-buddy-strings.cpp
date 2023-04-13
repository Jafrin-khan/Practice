/*
Idea

Using 2 indices diff1, diff2 to store up to 2 different places between string A and string B.
If there are more than 2 different places -> Invalid.
If there are 2 different places -> Compare A[diff1] vs B[diff2] and A[diff2] vs B[diff1].
If there is only 1 different places -> Invalid.
If no difference between A and B then check if A contains at least 1 duplicate letters so that we can swap them.
Example 1: A = "ab", B = "ab"
Example 2: A = "aab", B = "aab",

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int diff1 = -1, diff2 = -1;
        unordered_set<char> A_letters;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (diff1 == -1)
                    diff1 = i;
                else if (diff2 == -1)
                    diff2 = i;
                else
                    return false; // More than 2 different places between A & B
            }
            A_letters.insert(A[i]);
        }
        if (diff1 != -1 && diff2 != -1) // There are 2 different places
            return A[diff1] == B[diff2] && A[diff2] == B[diff1]; 
        if (diff1 != -1) // Only have 1 different place
            return false;
        return A_letters.size() < A.size(); // No different between A & B, check if A contains at least 1 duplicate letters.
    }
};
Complexity:

Time: O(N)
Space: O(26), A_letters stores up to 26 characters
If you like this solution, I'm happy if you give this post a vote.
Happy coding!
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size() != goal.size()) return false;
        
        set<char> st;
        int diff1 = -1 , diff2 = -1;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != goal[i]){
                if(diff1 == -1) diff1 = i;
                else if(diff2 == -1) diff2 = i;
                else return false;
            }
            st.insert(s[i]);
        }
        
        if(diff1 != -1 && diff2 != -1) return s[diff1] == goal[diff2] && s[diff2] == goal[diff1];
        if(diff1 != -1 || diff2 != -1) return false;
        
        return st.size() < s.size();
        
    }
};