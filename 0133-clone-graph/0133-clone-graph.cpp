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
    
    //Write this code again
    Node* cloneGraph(Node* sourceNode) {
       if(sourceNode == NULL) return sourceNode;
        
        queue<Node*> q;
        unordered_map<Node*,Node*> mp;
        
        q.push(sourceNode);
        mp[sourceNode] = new Node(sourceNode->val);
        
        while(!q.empty()){
            Node* parent = q.front();
            q.pop();
            
            for(auto it : parent->neighbors){
                if(mp.find(it) == mp.end()){
                    Node* child = new Node(it->val);
                    mp[it] = child;
                    q.push(it);
                    
                }
                
                mp[parent]->neighbors.push_back(mp[it]);
            }
        }
        return mp[sourceNode];
    }
};