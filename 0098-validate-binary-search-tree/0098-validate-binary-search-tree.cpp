
class Solution {
public:
    
    bool f(TreeNode* root , TreeNode* maxi , TreeNode* mini){
        
        if(root == NULL) return true;
        
        if((mini != NULL && root->val <= mini->val) || (maxi != NULL && root->val >= maxi->val)) return false;
        
        return f(root->left , root , mini) && f(root->right , maxi , root);
    }
    bool isValidBST(TreeNode* root) {
        return f(root , NULL , NULL);
    }
};