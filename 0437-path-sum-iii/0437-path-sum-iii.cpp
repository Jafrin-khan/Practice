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

If we assume counts of nodes in this tree is n, the recursion will run on n + (n/2)*2 + (n/4)*4 + … + 1*n nodes. Therefore, it’s time complexity is O(nlogn).

For space complexity, the maximum calls in calling stack will be h if h denotes to the length of the deepest path in this tree. Thus, it uses O(h) extra space. Or you can say O(logn) because h is bounded by logn.

*/
    
  /*
  TC = O(nlogn)
  SC = O(h)
  */
  void f(TreeNode* root , long long k , int& cnt){

        if(root == NULL){
            return;
        }
      
        if(k == root->val){
            cnt++;
        }

        f(root->left , k - root->val , cnt);
        f(root->right , k - root->val , cnt);
 
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == NULL){
            return 0;
        }
        
        long long k = targetSum;
        
        int cnt = 0;
        f(root , k , cnt);

        return cnt + pathSum(root->left , k) + pathSum(root->right , k);

        
    }
};