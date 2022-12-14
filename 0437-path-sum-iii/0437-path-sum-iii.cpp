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
  void f(TreeNode* root , long long k , int& cnt){

        if(root == NULL){
            return;
        }
      
        if(k == root->val){
            cnt++;
        }

        f(root->left , k - root->val , cnt);
        f(root->right , k - root->val , cnt);
 
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == NULL){
            return 0;
        }
        
        long long k = targetSum;
        
        int cnt = 0;
        f(root , k , cnt);

        return cnt + pathSum(root->left , k) + pathSum(root->right , k);

        
    }
};