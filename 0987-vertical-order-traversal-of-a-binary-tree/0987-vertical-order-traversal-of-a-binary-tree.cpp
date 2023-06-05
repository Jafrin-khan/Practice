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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> mp; //<vertical,<level,multiset<int>>>
        queue<pair<TreeNode*,pair<int,int>>> q;//<node,<vertical,level>>

        q.push({root , {0 , 0}});

        while(!q.empty()){
            TreeNode* node = q.front().first ;
            int vertical = q.front().second.first;
            int level = q.front().second.second;q.pop();

            mp[vertical][level].insert(node->val);

            if(node->left){
                q.push({node->left,{vertical-1 , level+1}});
            }

            if(node->right){
                q.push({node->right,{vertical+1 , level+1}});
            }

        }

        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> v;
            for(auto itt : it.second){
                v.insert(v.end() , itt.second.begin() , itt.second.end());/////////////////////////
            }
            ans.push_back(v);
        }
        return ans;
    }
};