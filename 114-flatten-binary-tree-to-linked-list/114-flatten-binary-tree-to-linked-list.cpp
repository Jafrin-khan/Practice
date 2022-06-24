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
          if(root == NULL || (root->left == NULL && root->right == NULL)){
            return root;
        }
            
        TreeNode* left = f(root->left);
        TreeNode* right = f(root->right);
        
        root->right = left;
        
        TreeNode* traverse = root;
        while(traverse->right != NULL){
            traverse = traverse->right;
        }
        
       traverse->right = right;
       root->left = NULL;
        
        return root;
    }
    void flatten(TreeNode* root) {
        
     f(root);
        
        
        
    }
};