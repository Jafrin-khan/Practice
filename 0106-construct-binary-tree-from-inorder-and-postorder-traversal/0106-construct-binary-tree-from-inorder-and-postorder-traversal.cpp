class Solution {
public:
    TreeNode* f(int& ind , int si , int ei , vector<int>& inorder , vector<int>& postorder){
        if(si > ei) return NULL;
        int value = postorder[ind];
        ind--;
        TreeNode* root = new TreeNode(value);
        
        int idx;
        for(int i = si ; i <= ei ; i++){
            if(inorder[i] == value){
                idx = i;
                break;
            }
        }
        
        root->right = f(ind , idx+1 , ei , inorder , postorder);
        root->left = f(ind , si , idx-1 , inorder , postorder);
        
        return root;  
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = postorder.size()-1;
        return f(ind , 0 , inorder.size()-1 , inorder , postorder);
    }
}; 