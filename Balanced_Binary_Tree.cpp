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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(root == nullptr) return true;
        
        const int left_depth = maxDepth(root->left);
        const int right_depth = maxDepth(root->right);
        
        return abs(left_depth-right_depth)<=1 
               && isBalanced(root->left) 
               && isBalanced(root->right);
    }
private:
    int maxDepth(TreeNode *root) {
        return root==nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
