/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode d(0);
        d.next = head;
        
        ListNode *p = &d;
        int c = 0;
        while(p) {
            ++c;
            p=p->next;
        }
        p = &d;
        int k = c - n - 1;
        while(k--) {
            p=p->next;
        }
        p->next = p->next->next;
        
        return d.next;
    }
};
