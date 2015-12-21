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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LLONG_MAX, LLONG_MIN);
    }
    
    bool isValidBST(TreeNode* root, long long max_val, long long min_val) {
        if(!root) return true;
        if(root->val >= max_val || root->val <= min_val) return false;
        
        if(!isValidBST(root->left, root->val, min_val)) return false;
        if(!isValidBST(root->right, max_val, root->val)) return false;
        
        return true;
    }
};
