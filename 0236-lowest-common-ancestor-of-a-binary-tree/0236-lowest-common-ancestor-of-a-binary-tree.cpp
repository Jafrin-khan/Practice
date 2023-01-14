/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
TC = O(N)
SC = O(N)
*/
class Solution {
public:
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root == NULL){
            return root;
        }
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* left = lca(root->left , p , q);
        TreeNode* right = lca(root->right , p , q);
        
        if(left && right){
            return root;
        }
        
        return left == NULL ? right : left;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};