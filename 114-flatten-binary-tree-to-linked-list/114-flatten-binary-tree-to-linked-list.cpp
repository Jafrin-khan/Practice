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
        
        if(root == NULL){
            return root;
        }
        
        TreeNode* leftPart = f(root->left);
        TreeNode* rightPart = f(root->right);
        
        TreeNode* temp = NULL;
        if(root->right){
            temp = root->right;
        }
        
        root->right = root->left;
        root->left = NULL;
        
        TreeNode* traverse = root;
        while(traverse->right){
            traverse = traverse->right;
        }
        
        traverse->right = temp;
        
        return root;
        
    }
    void flatten(TreeNode* root) {
        
        f(root);
    }
};