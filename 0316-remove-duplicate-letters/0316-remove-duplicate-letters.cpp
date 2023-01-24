/*
This solution is based on the idea that if characters c2 appears before c1 in string order, and c2 appears again after c1, then we must discard the c2 that is before c1, if c1 has higher order than c2 (c1 < c2).

For example, if we have bcabc.
We insert b and c normally, since they are both unique, and b is higher order than c. Then we see an a. By inspection, we know that there is a b and c that appears after a. What that means is that we can safely discard the b and c before a, since they will eventually re-appear after a, and because they re-appear after a, no unique string combination with b and c before a will have higher lexigraphical order than those withb and c appear some position after a.

Similarly, if there is no b and c after a, as in the case of bca, then we keep the b and c where they are. In other words, we try to move lower order characters whenever possible (they appear later).

By applying the same argument to all the characters we encounter, we will see that the position of each character is the one that matches the highest lexigraphical order.

Implementation

To check if a character appears later, we can do a count. We start by using a vector to store the counts of all characters, and at each iteration going through the string, we decrease count of the current character. Thus, we will know if a character will "appear later" if its count is not 0.

We also need a visited array. This is because when we go through the string, we need to skip characters that are already in our solution string. This is because our solution string is always in the highest lexigraphical order, and new characters that are duplicates of those in the solution string will not change the order, because we have already taken that into account. Since we check if characters in solution string will "appear later", so all characters that result in better orders if they appear later are removed, so they are no longer "visited", and those that "will not" have a better order if they appear later are kept, so there is no need to bother with these characters, since it is not possible for them to change the current best order. Thus, solution string always has the highest lexigraphical order.


*/

class Solution {
public:
    string removeDuplicateLetters(string s){
    
        vector<int> cnt(26,0);
        vector<int> vis(26,0);
        for(auto it : s) cnt[it-'a']++;
        
        string ans = "";
        
        for(auto it : s){
            --cnt[it-'a'];
            if(ans.empty()){
               ans += it;
               vis[it-'a'] = 1;
               continue;
            }
            if(vis[it-'a'])continue;
            while(!ans.empty() && ans.back() > it && cnt[ans.back() - 'a']){
            vis[ans.back() - 'a'] = 0;
            ans.pop_back();
            }
            
            vis[it-'a'] = 1;
            ans += it;
            
        }
        
        return ans;
    }
};