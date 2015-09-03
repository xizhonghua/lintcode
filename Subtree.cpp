/**
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if(!T2) return true;
        if(!T1) return false;
        
        return isSameTree(T1, T2) 
               || isSubtree(T1->left, T2) 
               || isSubtree(T1->right, T2);
    }
private:
    bool isSameTree(TreeNode* T1, TreeNode* T2) {
        if(!T1 && !T2) return true;
        if(!T1 || !T2) return false;
        return T1->val == T2->val 
               && isSameTree(T1->left, T2->left) 
               && isSameTree(T1->right, T2->right);
    }
};
