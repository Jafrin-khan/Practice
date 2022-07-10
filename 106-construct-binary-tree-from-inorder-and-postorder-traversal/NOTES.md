class Solution {
public:
TreeNode* node(vector<int>& inorder, vector<int>& postorder,int sp,int ep,int si,int ei){
if(si > ei || sp > ep){
return NULL;
}
int root_val = postorder[ep];
TreeNode* newNode = new TreeNode(root_val);
int idx;
for(int i = si ; i <= ei ; i++){
if(inorder[i] == root_val){
idx = i;
break;
}
}
newNode->left = node(inorder,postorder,sp,sp-(si-idx)-1,si,idx-1);
newNode->right = node(inorder,postorder,sp-(si-idx),ep-1,idx+1,ei);
return newNode;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
return node(inorder, postorder,0,postorder.size()-1,0,inorder.size()-1);
}
};