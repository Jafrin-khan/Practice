
class Solution {
public:
    
    TreeNode* f(int& ind , int si , int ei , vector<int>& preorder, vector<int>& inorder){
        
        if(si > ei) return NULL;
        
        int value = preorder[ind];
        TreeNode* root = new TreeNode(value);
        ind++;
        
        int idx;
        for(int i = si ; i <= ei ; i++){
            if(inorder[i] == value){
                idx = i;
                break;
            }
        }
        
        root->left = f(ind , si , idx-1 , preorder , inorder);
        root->right = f(ind , idx+1 , ei , preorder , inorder);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return f(ind , 0 , inorder.size()-1 , preorder , inorder);
    }
};