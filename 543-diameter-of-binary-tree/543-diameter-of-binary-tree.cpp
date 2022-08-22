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
        
        if(root == NULL){
            return 0;
        }
        
        int lh = h(root->left);
        int rh = h(root->right);
        
        return max(lh,rh) + 1;
    }
    
    int d(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int ld = d(root->left);
        int rd = d(root->right);
        
        return max({ld , rd , h(root->left) + h(root->right)});
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return d(root);
        
    }
};