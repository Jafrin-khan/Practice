/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* cur , unordered_map<Node* , Node*>& mp){
        
        vector<Node*> v;
        Node* clone = new Node(cur->val);
        mp[cur] = clone;
        
        for(auto it : cur->neighbors){
            if(mp.find(it) != mp.end()){
                v.push_back(mp[it]);
            }
            
            else{
                v.push_back(dfs(it , mp));
            }
        }
        
        clone->neighbors = v;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        
        if(node == NULL){
            return NULL;
        }
        
        //if only one node is there then we return its clone straighaway
        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
        
    }
};