class Solution {
public:
​
​
TreeNode * construct(vector<int> &preorder, unordered_map<int, int> &inorder_map,
int &pre_index, int start, int end)
{
if(start > end){
return NULL;
}
TreeNode * root = new TreeNode(preorder[pre_index]);
++pre_index;
if(start == end){
return root;
}
int root_index = inorder_map[root->val];
root->left = construct(preorder, inorder_map, pre_index, start, root_index-1);
root->right = construct(preorder, inorder_map, pre_index, root_index+1, end);
return root;
}
​
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
int n = inorder.size();
unordered_map<int, int> inorder_map;
for(int i=0; i<n; i++){
inorder_map[inorder[i]] = i;
}
int pre_index = 0;
TreeNode * root = construct(preorder, inorder_map, pre_index, 0, n-1);
return root;
}
};