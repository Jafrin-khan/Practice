/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*

One brute force method is also there using hashmaps see TUF notes

Time Complexity: O(N)+O(N)+O(N)

Reason: Each step takes O(N) of time complexity.

Space Complexity: O(1)

Reason: No extra data structure was used for computation.

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return head;
        }
        
        Node* temp = head;
        
        //make copy of nodes and linking nodes by next pointers ONLY
        /*
        eg = 1->2->3->4
             1->1->2->2->3->3->4->4
        */
        while(temp!=NULL){
            
            Node* nextNode = temp->next;
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = nextNode;
            
            temp = temp->next->next;
        }
        
        //linking random pointers
        temp = head;
        while(temp != NULL){
            
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            
            temp = temp->next->next;
        }
        
        //segragating the lists
        temp = head;
        Node* newHead = new Node(0);
        Node* tail = newHead;
        
        while(temp != NULL){
            
            tail->next = temp->next;
            tail = tail->next;
                
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        return newHead->next;
        
    }
};