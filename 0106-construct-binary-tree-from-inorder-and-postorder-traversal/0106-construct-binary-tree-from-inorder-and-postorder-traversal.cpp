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

     TreeNode* f(int& ind , int si , int ei , vector<int>& postorder, vector<int>& inorder){
        
        if(si > ei) return NULL;
        
        TreeNode* root = new TreeNode(postorder[ind]);
        ind--;
        
        int idx;
        for(int i = si ; i <= ei ; i++){
            if(inorder[i] == root->val){
                idx = i;
                break;
            }
        }
        
        root->right = f(ind , idx+1 , ei , postorder , inorder);
        root->left = f(ind , si , idx-1 , postorder , inorder);
        
        return root;
        
    }
   
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int ind = postorder.size()-1;
       return f(ind , 0 , inorder.size()-1 , postorder , inorder);
    }
};