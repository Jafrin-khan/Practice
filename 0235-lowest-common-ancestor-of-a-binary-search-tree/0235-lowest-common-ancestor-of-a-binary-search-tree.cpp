/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* f(TreeNode* root , TreeNode* p, TreeNode* q){
        
        if(root == NULL) return root;
        
        if(root->val == p->val || root->val == q->val) return root;
        
        TreeNode* left = f(root->left , p , q);
        TreeNode* right = f(root->right , p , q);
        
        if(left &&  right) return root;
        
        return left == NULL ? right : left;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return f(root , p , q);
    }
};