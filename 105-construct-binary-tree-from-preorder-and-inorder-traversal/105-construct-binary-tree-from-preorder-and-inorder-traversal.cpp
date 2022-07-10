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
    
    int getIndex(vector<int>& inorder , int value , int start , int end ){
        
        for(int i = start ; i <= end ; i++){
            if(inorder[i] == value){
                return i;
            }
        }
        
        return -1;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder ,int& prefixInd, int start , int end){
        
     
        if(start > end){
            return NULL;
        }
       
        TreeNode* root = new TreeNode(preorder[prefixInd]);
        prefixInd++;
         
        if(start == end){
            return root;
        }
        
        int ind = getIndex(inorder , root->val , start , end);
        
        root->left = build(preorder , inorder,prefixInd , start , ind-1);
        root->right = build(preorder , inorder ,prefixInd , ind + 1 , end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int prefixIndex = 0;
        return build(preorder , inorder , prefixIndex, 0 , inorder.size()-1);
    }
};