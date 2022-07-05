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
    
    TreeNode* helper(int& i , int bound , vector<int>& preorder){
        
        if(i >= preorder.size() || preorder[i] > bound){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = helper(i , node->val , preorder);
        node->right = helper(i , bound , preorder);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(i , INT_MAX , preorder);
    }
};