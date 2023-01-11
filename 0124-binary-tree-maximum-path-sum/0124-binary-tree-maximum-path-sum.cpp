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

                 -10   m=42 , s = 25
                /    \ 
             9        20   m=42 , s=35                     15,20,7 = 42
           s=9       /  \
           m=9     15    7
                   m=15    m=7
                   s=15     s=7

*/
    
    /*
Time Complexity: O(N).

Reason: We are doing a tree traversal.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
    */
    int f(TreeNode* root , int& maxSum){
        
        if(root == NULL){
            return 0;
        }
        
        int sumLeft = max(0 , f(root->left , maxSum));
        int sumRight = max(0 , f(root->right , maxSum));
        
        maxSum = max(maxSum , sumLeft + sumRight + root->val);
        
        return max(sumLeft , sumRight) + root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int maxSum = -1e9;
        f(root , maxSum);
        
        return maxSum;
    }
};