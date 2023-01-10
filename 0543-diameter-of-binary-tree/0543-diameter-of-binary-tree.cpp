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
OPTIMISED APPROACH
TC is reduced since height and diameter are calculated in the same function function....main approach is in previous submission
TC = O(N)
SC = O(N)...recursive stack
*/

class Solution {
public:
    
    int d(TreeNode* root , int& height){
        
        if(root == NULL){
            height = 0;
            return 0;
        }
        
        int lh = 0;
        int rh = 0;
        
        int ld = d(root->left , lh);
        int rd = d(root->right , rh);
        
        height = max(lh , rh) +1;
        
        return max({lh + rh + 1 , ld , rd});
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int height = 0;
        return d(root , height)-1;
    }
};