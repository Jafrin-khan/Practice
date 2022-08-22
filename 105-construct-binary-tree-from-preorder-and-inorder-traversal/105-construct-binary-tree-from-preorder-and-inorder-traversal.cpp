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
    
    TreeNode* f(vector<int>& preorder, vector<int>& inorder ,int& preInd , int start , int end){
        
        if(start > end){
            return NULL;
        }
        int first = preorder[preInd];
        preInd++;
        TreeNode* node = new TreeNode(first);
        
        if(start == end){
            return node;
        }
        
        int ind;
        for(int i = start ; i <= end ; i++){
            
            if(inorder[i] == first){
                ind = i;
                break;
            }
        }
        
        node->left = f(preorder , inorder , preInd , start , ind-1);
        node->right = f(preorder , inorder , preInd , ind+1 , end);
        
        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preInd = 0;
        return f(preorder , inorder , preInd , 0 , inorder.size()-1);
    }
};