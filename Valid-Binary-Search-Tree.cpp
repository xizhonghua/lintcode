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
        bool fl = true;
        if(root->left) {
            if(root->val <= root->left->val) return false;
            fl = isValidBST(root->left, root->val, min_val);
        }
        bool fr = true; 
        if(root->right) {
            if(root->val >= root->right->val) return false;
            fr = isValidBST(root->right, max_val, root->val);
        }
        return fl && fr;
    }
};
