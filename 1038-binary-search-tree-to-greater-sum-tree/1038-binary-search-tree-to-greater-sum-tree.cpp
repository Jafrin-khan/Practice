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
    TC = O(N)
    SC = O(H) ...... If we don’t consider the size of the stack for function calls then O(1) otherwise O(h) where h is the height of the tree.   
    */
    
    void sumOfAllNodes(TreeNode* root , int& sum){
        
        if(root == NULL){
            return;
        }
        
        sum += root->val;
        
        sumOfAllNodes(root->left , sum);
        sumOfAllNodes(root->right , sum);
        
    }
    
    void calculate(TreeNode* root , int& sum){
        
        if(root == NULL){
            return;
        }
        //simple inorder
        calculate(root->left , sum);
        
        int x = root->val;
        root->val = sum;
        sum -= x;
        
        calculate(root->right , sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        sumOfAllNodes(root , sum);
        calculate(root , sum);
        
        return root;
    }
};