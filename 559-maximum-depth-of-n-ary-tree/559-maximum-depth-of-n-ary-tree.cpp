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
    int maxDepth(Node* root) {
        
        if(root == NULL){
            return 0;
        }
        
        vector<Node*> cd = root->children;
        int maxHeight = 0;
        
        for(int i = 0 ; i < cd.size() ; i++){
            
            int cmpHeight = maxDepth(cd[i]) ;
            maxHeight = max(maxHeight ,cmpHeight);
        }
        
        return maxHeight+1;
    }
};