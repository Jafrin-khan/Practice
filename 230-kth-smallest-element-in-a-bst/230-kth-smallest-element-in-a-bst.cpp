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
    
    int counter = 0;
    
    void f(TreeNode* root , int &ans , int k){
        
        if(root == NULL){
            return;
        }
        
        f(root->left , ans , k);
        
        counter++;
        if(counter == k){
            ans = root->val;
            return;
        }
        
        f(root->right , ans , k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans;
        f(root , ans , k);
        return ans;
    }
};