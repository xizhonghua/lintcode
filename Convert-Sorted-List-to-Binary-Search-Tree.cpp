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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        int l = len(head);
        if(l==0) return NULL;
        if(l==1) return new TreeNode(head->val);
        
        auto m = head, p = head;
        int c = (l-1)/2;
        while(c--) { p = m; m = m->next; }
        
        auto n = new TreeNode(m->val);
        n->right = sortedListToBST(m->next);
        
        p->next = NULL;
        n->left = m==head ? NULL : sortedListToBST(head);
        return n;
    }
    
    int len(ListNode* head) {
        int l = 0;
        while(head) { head=head->next; ++l; }
        return l;
    }
};



