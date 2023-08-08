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
    
    void f(TreeNode* root , string path , vector<string>& ans){
        
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            path = path + "->" + to_string(root->val);
            ans.push_back(path.substr(2));
            return;
        }
        path = path + "->" + to_string(root->val);
        f(root->left , path , ans);
        f(root->right , path , ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        f(root  , "" , ans);
        
        return ans;
        
    }
};