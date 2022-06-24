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
    int i = 0;
     vector<int> v;
    void storeInorder(TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        storeInorder(root->left);
        v.push_back(root->val);
        storeInorder(root->right);
        
    }
    
    void helper(TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        helper(root->left);
        if(v[i]!=root->val)
        {
            swap(v[i],root->val);
        }
        i++;
        helper(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        
      
        storeInorder(root);
        sort(v.begin(),v.end());
        
        helper(root);
        
       
    }
};