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
class BSTIterator {
public:
    
    vector<int> inorder;
    int ind;
    
    void storeIno(TreeNode* root){
        
        if(root == NULL) return;
        
        storeIno(root->left);
        inorder.push_back(root->val);
        storeIno(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        storeIno(root);
        ind = 0;
    }
    
    int next() {
        return inorder[ind++];
    }
    
    bool hasNext() {
        if(ind < inorder.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */