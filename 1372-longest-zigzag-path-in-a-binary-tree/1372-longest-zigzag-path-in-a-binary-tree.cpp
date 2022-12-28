/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
State of Node A:

l : max zigag length where A is reached by moving left from parent
r : max zigag length where A is reached by moving right from parent
Usually, one of them is always 0, bec at a time only one type of pattern exists either R->L or L->R so other becomes 0.
At a node if we reached it by moving LEFT from parent then its params would be(l=0,r=XYZ). We need to go RIGHT from there to continue current pattern so now we send the l=r+1. Similarly when reached A by RIGHT move.
** Basically we should move in LEFT if l>0 OR RIGHT if r>0 for pattern to continue, and send in r=prevL+1 OR l=prevR+1 respectively telling next recursion what pattern to continue.
l>0 : tells last pattern formed has moved RIGHT to reach current node, thus we should move LEFT for continuing pattern.

----- for better understanding try it on a tree -----
*/
class Solution {
public:
    
    /*
    check this TC and SC from friend
    TC = O(N)
    SC = O(N)...stack space
    */
    
    void ziggy(TreeNode* root, int l , int r, int& ans){
        if(!root) return;
         ans = max(ans, l);
         ans = max(ans, r);
        ziggy(root->left, 0, l+1, ans);
        
        ziggy(root->right, r+1, 0, ans);
        
        return;
    }
    int longestZigZag(TreeNode* root) {
        int l=0;
        int r=0;
        int ans=0;
        ziggy(root, l,r,ans);
        return ans;
    }
};