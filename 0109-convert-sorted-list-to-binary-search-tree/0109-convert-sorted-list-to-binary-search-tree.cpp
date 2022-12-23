

class Solution {
public:
    
    TreeNode* f(int i , int j , vector<int>& arr){
        if(i > j){
            return NULL;
        }
        
        int mid = i + (j-i)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = f(i , mid-1 , arr);
        root->right = f(mid+1 , j , arr);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> arr;
        ListNode* temp = head;
        
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        TreeNode* root = f(0 , arr.size()-1 , arr);
        
        return root;
        
    }
};