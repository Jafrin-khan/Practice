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
    
    TreeNode* subTree(TreeNode* root , int data){
        
        if(root == NULL){
            return root;
        }
        
        if(root->val == data){
            return root;
        }
        
        root->left = subTree(root->left , data) ;
        root->right = subTree(root->right , data);
        
        return root->left == NULL ? root->right : root->left;
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return subTree(root , val);
        
        
        
    }
};