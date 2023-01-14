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
    
    /*
    TC = 
    SC = 
    */
    
    TreeNode* f(int& ind , int si , int ei , vector<int>& preorder, vector<int>& inorder){
        
        if(si > ei){
            return NULL;
        }
        
        int idx;
        for(int i = si ; i <= ei ; i++){
            if(inorder[i] == preorder[ind]){
                idx = i;
                break;
            }
        }
        
        TreeNode* node = new TreeNode(preorder[ind]);
        ind++;
        
       
        node->left = f(ind , si , idx-1 , preorder , inorder);
        node->right = f(ind , idx+1 , ei , preorder , inorder);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int ind = 0;
        return f(ind , 0 , inorder.size()-1 , preorder , inorder);
    }
};