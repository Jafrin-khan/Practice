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
Time Complexity: O(N)

Reason: We are doing a simple preorder traversal.

Space Complexity: O(N)

Reason: Worst case time complexity will be O(N) (in case of skewed tree).
    */
    
    /*
    TC = O(N)
    SC = O(N)....worst TC in case of skewed tree.....we can do SC as O(1) using Morris Traversal
    */
    
    TreeNode* f(TreeNode* root){
        
         if(root == NULL){
            return root;
        }
        
        TreeNode* leftPart = f(root->left);
        TreeNode* rightPart = f(root->right);
        
        root->right = leftPart;
        root->left = NULL;
        TreeNode* traverse = root;
        
        while(traverse->right){
            traverse = traverse->right;
        }
        
        traverse->right = rightPart;
        
        return root;
        
    }
    
    void flatten(TreeNode* root) {
        
        if(root == NULL){
            return;
        }
        
        f(root);
    }
};