class Solution {
public:
vector<int> preorder(Node* root) {
if(root==nullptr)//base condition -> return empty vector
return {};
vector<Node*> children = root->children;
vector<int> retval;
retval.push_back(root->val);// add the root
for(int i=0;i<children.size();i++)
{
vector<int> x = preorder(children[i]);
retval.insert(retval.end(),x.begin(),x.end());// add childern of root
}
return retval;
}
};