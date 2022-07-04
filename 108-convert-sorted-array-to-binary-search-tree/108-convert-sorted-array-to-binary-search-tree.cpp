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
    
    TreeNode* helper(int start , int end , vector<int>& nums){
        
        if(start > end){
            return NULL;
        }
        
        int mid = (start+end)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        
        newNode->left = helper(start , mid-1 , nums);
        newNode->right = helper(mid+1 , end , nums);
        
        return newNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0){
            return NULL;
        }
    
        return helper(0 , nums.size()-1 , nums);
        
    }
};