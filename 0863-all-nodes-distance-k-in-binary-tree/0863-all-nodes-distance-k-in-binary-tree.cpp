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
       vector<int>v;
    //CASE 1 ---> When we are checking in subtree of target
    void checkSubTree(TreeNode* root,TreeNode* target,int k){
        if(!root || k<0)return ;
        if(k==0){v.push_back(root->val);return;}
        checkSubTree(root->left,target,k-1);
        checkSubTree(root->right,target,k-1);
    }
    
    //CASE 2 ---> When we are checking in parent/ancestor subtree of target
    int checkParent(TreeNode* root,TreeNode* target,int k){
        if(!root)return -1;
        if(root==target){
            checkSubTree(root,target,k);
            return 0;
        }
        int left_distance=checkParent(root->left,target,k); //equation 1
        if(left_distance!=-1){//i.e we found our target in left subtree
            if(left_distance+1==k)v.push_back(root->val);
            else checkSubTree(root->right,target,k-left_distance-2); //-2 because we ignore the distance between root to root->right here which is one unit and also ignore one unit diatsnce from root to root->left in ewuation 1
            return 1+left_distance;
        }
         int right_distance=checkParent(root->right,target,k);
        if(right_distance!=-1){//i.e we found our target in right subtree
            if(right_distance+1==k)v.push_back(root->val);
            else checkSubTree(root->left,target,k-right_distance-2);
            return 1+right_distance;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        checkParent(root,target,k);
        return v;
    }
};