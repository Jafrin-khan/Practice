
class Solution {
public:
    
    TreeNode* f(int& idx , int start , int end , vector<int>& preorder, vector<int>& inorder){
        
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        
        int ind;
        for(int i = start ;  i <= end ; i++){
            if(inorder[i] == root->val){
                ind = i;
                break;
            }
        }
        
        root->left = f(idx , start , ind-1 , preorder , inorder);
        root->right = f(idx , ind+1 , end , preorder , inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        int idx = 0;
        return f(idx , 0 , n-1 , preorder , inorder);
    }
};