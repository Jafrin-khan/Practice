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
    TC = O(N)
    SC = O(N)
    */
    
    TreeNode* firstMistake, *secondMistake, *pre;
    void inorder(TreeNode* root) {
		if(root == nullptr) 
			return;

		inorder(root->left);

		if(firstMistake == nullptr && root->val < pre->val)
			firstMistake = pre;
		if(firstMistake != nullptr && root->val < pre->val)
			secondMistake = root;
		pre = root;

		inorder(root->right);
	}
	void recoverTree(TreeNode* root) {
		pre = new TreeNode(INT_MIN);
		inorder(root);
        
        cout<<firstMistake->val<<" "<<secondMistake->val;
		swap(firstMistake->val, secondMistake->val);
	}

	
};