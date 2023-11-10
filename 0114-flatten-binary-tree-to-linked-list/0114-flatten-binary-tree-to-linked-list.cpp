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
     TreeNode* f(TreeNode* root){
        
        if(root == NULL) return root;
        
        TreeNode* ll = f(root->left);
        TreeNode* rl = f(root->right);
        
        root->right = ll;
        TreeNode* traverse = root;
        
        while(traverse->right){
            traverse = traverse->right;
        }
        
        traverse->right = rl;
        root->left = NULL;
        
        return root;
    }
    
    void flatten(TreeNode* root) {
        f(root);
    }
};