/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        ans.push_back(root->val);
        
        vector<Node*> cd = root->children;
        
        for(int i = 0 ; i < cd.size() ; i++){
            
            vector<int> toReturn = preorder(cd[i]);
            ans.insert(ans.end() , toReturn.begin() , toReturn.end());
        }
        
        return ans;
    }
};