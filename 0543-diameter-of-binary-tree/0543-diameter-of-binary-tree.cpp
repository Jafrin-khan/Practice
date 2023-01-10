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
    TC = O(N^2)
    SC = O(N)//recursive stack
    */
    int h(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(h(root->left),h(root->right)) + 1;
    }
    
    int d(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = h(root->left);
        int rh = h(root->right);
        
        int dia = lh + rh + 1;
        return max({dia , d(root->left) , d(root->right)});
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        //remeber this -1 bcoz while calculating diameter we considered this root twice hence has to subtract it once
        return d(root) -1;
       
    }
};