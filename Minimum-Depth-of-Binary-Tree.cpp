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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(root->left && root->right) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        } else if(root->left) {
            return 1 + minDepth(root->left);
        } else {
            return 1 + minDepth(root->right);
        }
        return INT_MAX;
    }
};
