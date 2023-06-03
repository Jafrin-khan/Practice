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
    //Recursion
    //TC = O(N)
    //SC = O(N)
    
     void preOrder(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;
        
        ans.push_back(root->val);
        preOrder(root->left , ans);
        preOrder(root->right , ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root , ans);
        
        return ans;
    }
    */
    
    /*
    //Iterative
    //TC = O(N)
    //SC = O(N)
    vector<int> preorderTraversal(TreeNode* curr) {
          vector < int > preOrder;
          if (curr == NULL)
            return preOrder;

          stack <TreeNode * > s;
          s.push(curr);

          while (!s.empty()) {
            TreeNode * topNode = s.top();
            preOrder.push_back(topNode -> val);
            s.pop();
            if (topNode -> right != NULL)
              s.push(topNode -> right);
            if (topNode -> left != NULL)
              s.push(topNode -> left);
          }
          return preOrder;
            }
    */
    

    //Morris
    //TC = O(N)
    //SC = O(1)
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* curr = root;
        
        while(curr != NULL){
            
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == curr){
                    prev->right = NULL;
                    curr = curr->right;
                }
                
                else{
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
            }
        }
        
        return ans;
    }

};