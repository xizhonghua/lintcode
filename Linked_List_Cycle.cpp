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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        auto slow = head;
        auto fast = head;
        
        while(fast != nullptr)
        {
            if(fast->next == nullptr || fast->next->next == nullptr) return false;
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) return true;
        }
        
        return false;
    }
};



