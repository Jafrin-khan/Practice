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
    
    void store(TreeNode* root , string ans , vector<string> &toFill){
        
        if(root == NULL){
            return;
        }
        
         if(root->left == NULL && root->right == NULL){
            ans+=(to_string(root->val));
            toFill.push_back(ans);
            return;
        }
        
        ans+=to_string(root->val);
        ans+="->";
        
        store( root->left ,  ans , toFill);
        store( root->right ,  ans , toFill);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> toFill;
        string ans = "";
        
        store(root , ans , toFill);
        
        return toFill;
        
    }
};