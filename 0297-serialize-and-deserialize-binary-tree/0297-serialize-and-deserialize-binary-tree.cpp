/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s = "";
        if(root == NULL) return s;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* root = q.front();q.pop();
            if(root == NULL) s += "#,";
            else s += (to_string(root->val) + ',');
            
            if(root != NULL){
                q.push(root->left);
                q.push(root->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        
        stringstream s(data);//allow to iterate over string treating characters as object
    
        string str;
        getline(s , str , ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            
            getline(s , str , ',');
            if(str == "#") node->left = NULL;
            else {
                node->left = new TreeNode(std::stoi(str));
                q.push(node->left);
            }
            getline(s , str , ',');
            if(str == "#") node->right = NULL;
            else{
                node->right = new TreeNode(std::stoi(str));
                q.push(node->right);
            } 
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));