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
    
    bool f(TreeNode* root , TreeNode* maxi , TreeNode* mini){
        if(root == NULL) return true;
        
        if((maxi != NULL && root->val >= maxi->val) || (mini != NULL && root->val <= mini->val)) return false;
        
        return f(root->left , root , mini) && f(root->right , maxi , root);
    }
    bool isValidBST(TreeNode* root) {
        return f(root , NULL , NULL);
    }
};