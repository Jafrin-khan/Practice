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
    
    TreeNode* f(int& ind , int bound , vector<int>& preorder){
        
        if(ind == preorder.size() || preorder[ind] >= bound){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[ind]);
        ind++;
        
        root->left = f(ind , root->val , preorder);
        root->right = f(ind , bound , preorder);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int ind = 0;
        return f(ind , 1e9 , preorder);
    }
};