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
    
  
    long long totalSum = 0 , result = 0;
    
    //total sum of all nodes
    void totSum(TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        totalSum += root->val;
        
        totSum(root->left);
        totSum(root->right);
    }
    
    
    //Find the totalSum under the root, including root.
    int sum(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        //Find the sum of left and right subtree under root.
        int sumL = sum(root->left);
        int sumR = sum(root->right);
        
        //Find the max product after making left or right subtrees as seprarate tree.
        result = max({result , (totalSum - sumL)*sumL , (totalSum-sumR)*sumR});
        
        //Return the sum of the  subtree which include current node (root node).
        return sumL + sumR + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        totSum(root);
        sum(root);
        
        return result%(1000000007);
        
        
    }
};