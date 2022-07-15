
class Solution {
public:
    
    TreeNode* f(int& ind , int bound , vector<int>& preorder){
        
        if(ind >= preorder.size() || preorder[ind] >= bound){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(preorder[ind++]);
        node->left = f(ind , node->val , preorder);
        node->right = f(ind , bound , preorder);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int ind = 0;
        return f(ind , INT_MAX , preorder);
    }
};