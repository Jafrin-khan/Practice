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
    vector<int> postorder(Node* root) {
        
        if(root == NULL){
            return {};
        }
        
        vector<int> ans;
     
        vector<Node*> cd = root->children;
        
        for(int i = 0 ; i < cd.size() ; i++){
            
            vector<int> toInsert = postorder(cd[i]);
            ans.insert(ans.end(),toInsert.begin(),toInsert.end());
        }
        ans.push_back(root->val);
        
        return ans;
        
        
    }
};