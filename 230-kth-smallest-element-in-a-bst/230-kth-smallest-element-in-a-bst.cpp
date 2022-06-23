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
    int ans;
    int counter = 0;
    void ansLao(TreeNode* root , int k){
        
        if(root == NULL || k < 0){
            return;
        }
        
        ansLao(root->left , k);
        counter++;
        if(counter == k){
            ans = root->val;
        }
        ansLao(root->right , k);
        
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        ansLao(root , k);
        return ans;
    }
};