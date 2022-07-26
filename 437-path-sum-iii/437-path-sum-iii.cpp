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
    
    int cnt = 0;
    void f(TreeNode* root, int targetSum ,long sum){
        
        if(root == NULL){
          return;
        }
        
        sum += root->val;
        if(sum == targetSum){
            cnt++;
        }
        
       f(root->left , targetSum , sum);
       f(root->right , targetSum , sum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL){
            return 0;
        }

        f(root , targetSum , 0);
        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);
        
        return cnt;
    }
};