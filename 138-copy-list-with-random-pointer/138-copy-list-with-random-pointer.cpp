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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
         if(head == NULL){
            return head;
        }
        
        Node* copy = new Node(0);
        Node* toReturn = copy;
        Node* itr = head;
        
        //creating deep copy
        while(itr != NULL){
            Node* newNode = new Node(itr->val);
            Node* nextNode = itr->next;
            itr->next = newNode;
            newNode->next = nextNode;
            itr = itr->next->next;
        }
        
        //pointing random pointers
        itr = head;
        
        while(itr != NULL){
            
            if(itr->random){
                itr->next->random = itr->random->next;
            }
            
            itr = itr->next->next;
            
        }
        
        itr = head;
        while(itr != NULL){
            
            copy->next = itr->next;
            itr->next = itr->next->next;
            itr = itr->next;
            copy = copy->next;
        }
        
        return toReturn->next;
        
    }
};