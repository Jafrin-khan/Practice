/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   /* Time Complexity: At first look the time complexity looks more than O(n), but if we take a closer look, we can observe that no node is traversed more than twice. Therefore the time complexity is O(n).*/
    
    vector<int> ans;
    void checkSubTree(TreeNode* root , TreeNode* target , int k){
        
        if(root == NULL || k < 0){
            return;
        }
        
         if(k == 0){
             ans.push_back(root->val);
             return;
         }
        
        checkSubTree(root->left , target , k-1);
        checkSubTree(root->right , target , k-1);  
    }
    
    int checkParent(TreeNode* root, TreeNode* target, int k){
        
        if(root == NULL){
            return -1;
        }
        
        if(root == target){
            checkSubTree(root , target , k);
            return 0;
        }
        
        int leftDistance = checkParent(root->left , target , k);
        if(leftDistance != -1){
            if(leftDistance + 1 == k){
                ans.push_back(root->val);
            }
            
            else{
                checkSubTree(root->right , target , k-leftDistance-2);
            }
            
            return 1 + leftDistance;
        }
        
        int rightDistance = checkParent(root->right , target , k);
        if(rightDistance != -1){
            
            if(rightDistance+1 == k){
                ans.push_back(root->val);
            }
            
            else{
                checkSubTree(root->left , target , k - rightDistance - 2);
            }
            
            return rightDistance+1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         checkParent(root,target,k);
        return ans;
        
    }
};