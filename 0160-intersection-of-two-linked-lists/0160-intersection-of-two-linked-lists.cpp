
class Solution {
public:
   
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        ListNode* d1 = head1;
        ListNode* d2 = head2;

        while(d1 != d2) {
            d1 = d1 == NULL? head2:d1->next;
            d2 = d2 == NULL? head1:d2->next;
        }

        return d1;
    }
};


// 4->1->8->4->5
//       |    
// 5->6->1->8->4->5
//          |
    
// len1 = 5
// len2 = 6
    
// d = 1
    
