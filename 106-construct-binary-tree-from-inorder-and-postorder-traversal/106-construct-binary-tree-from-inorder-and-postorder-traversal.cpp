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
    
    int getInd(vector<int>& inorder , int start , int end , int value){
        
        for(int i = start ; i <= end ; i++){
            if(inorder[i] == value){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int& postInd , int start , int end){
        
        if(start > end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postInd]);
        postInd--;
        
        if(start == end){
            return root;
        }
        
        int ind = getInd(inorder , start , end , root->val);
        
        root->right = build(inorder , postorder , postInd , ind+1 , end);
        root->left = build(inorder , postorder , postInd , start , ind-1);
       
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() == 0){
            return NULL;
        }
        
        int postInd =  postorder.size()-1;
        
        return  build(inorder , postorder , postInd , 0,  postorder.size()-1);
    }
};