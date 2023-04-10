class Solution {
public:
    
    int h(TreeNode* root){
        if(root == NULL) return 0;
        return max(h(root->left),h(root->right)) + 1; 
    }
    
    int dia(TreeNode* root){
        if(root == NULL) return 0;
        return max({h(root->left) + h(root->right) +1 ,dia(root->left) , dia(root->right)});
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root)-1;
    }
};