/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        ListNode d;
        d.next = head;
        ListNode* p = &d;
        while(head) {
            while(head && head->val == val) head=head->next;
            p->next = head;
            p = p->next;
            if(head) head = head->next;
        }
        return d.next;
    }
};
