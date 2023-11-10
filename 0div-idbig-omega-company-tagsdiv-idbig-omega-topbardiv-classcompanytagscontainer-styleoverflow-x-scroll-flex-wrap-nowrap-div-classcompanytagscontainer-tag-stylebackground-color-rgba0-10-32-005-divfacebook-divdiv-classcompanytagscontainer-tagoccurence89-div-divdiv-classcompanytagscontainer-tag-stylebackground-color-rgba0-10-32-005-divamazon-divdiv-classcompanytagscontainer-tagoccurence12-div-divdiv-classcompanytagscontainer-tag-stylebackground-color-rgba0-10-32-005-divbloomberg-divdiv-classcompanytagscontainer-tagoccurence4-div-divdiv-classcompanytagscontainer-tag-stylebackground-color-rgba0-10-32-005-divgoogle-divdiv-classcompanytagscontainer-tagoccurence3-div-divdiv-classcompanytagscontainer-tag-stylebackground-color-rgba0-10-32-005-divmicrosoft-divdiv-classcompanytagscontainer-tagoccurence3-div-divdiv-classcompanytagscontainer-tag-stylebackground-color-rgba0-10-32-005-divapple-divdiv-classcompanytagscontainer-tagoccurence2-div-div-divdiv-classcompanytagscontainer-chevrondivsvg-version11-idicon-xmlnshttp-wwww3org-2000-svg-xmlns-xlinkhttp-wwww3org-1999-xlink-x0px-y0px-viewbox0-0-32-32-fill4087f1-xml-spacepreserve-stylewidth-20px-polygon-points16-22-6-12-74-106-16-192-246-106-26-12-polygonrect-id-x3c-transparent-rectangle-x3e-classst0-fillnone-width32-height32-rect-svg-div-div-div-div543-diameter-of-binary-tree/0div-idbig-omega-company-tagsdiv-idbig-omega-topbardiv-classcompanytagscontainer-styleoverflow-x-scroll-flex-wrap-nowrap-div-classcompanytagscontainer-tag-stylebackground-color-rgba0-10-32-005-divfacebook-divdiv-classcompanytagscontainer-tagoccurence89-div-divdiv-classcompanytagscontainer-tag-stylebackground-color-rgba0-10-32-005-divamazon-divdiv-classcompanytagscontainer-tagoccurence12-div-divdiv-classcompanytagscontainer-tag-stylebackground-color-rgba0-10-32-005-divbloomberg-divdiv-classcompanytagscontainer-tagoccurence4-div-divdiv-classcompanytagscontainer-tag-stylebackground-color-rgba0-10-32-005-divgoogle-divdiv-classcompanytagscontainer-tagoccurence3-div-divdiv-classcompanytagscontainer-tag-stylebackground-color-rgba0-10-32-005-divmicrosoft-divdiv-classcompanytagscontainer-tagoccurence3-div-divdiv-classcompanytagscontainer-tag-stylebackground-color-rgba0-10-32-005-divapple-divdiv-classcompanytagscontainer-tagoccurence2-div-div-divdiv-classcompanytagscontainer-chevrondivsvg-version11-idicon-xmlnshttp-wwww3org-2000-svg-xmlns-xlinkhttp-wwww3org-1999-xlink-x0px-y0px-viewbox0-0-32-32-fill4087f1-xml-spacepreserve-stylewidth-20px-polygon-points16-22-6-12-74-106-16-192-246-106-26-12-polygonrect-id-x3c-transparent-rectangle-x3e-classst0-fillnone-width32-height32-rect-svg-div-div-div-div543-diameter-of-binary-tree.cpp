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
class Solution {
public:
    
    int h(TreeNode* root){
        if(root == NULL) return 0;
        return max(h(root->left) , h(root->right)) + 1;
    }
    
    int d(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int lh = h(root->left);
        int rh = h(root->right);
        
        return max({lh + rh + 1 , d(root->left) , d(root->right)});
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return d(root)-1;
    }
};