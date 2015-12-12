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
    int maxPathSum(TreeNode *root) {
        if(!root) return 0;
        
        long lp = root->left ? maxPathSum(root->left) : INT_MIN;
        long rp = root->right ? maxPathSum(root->right) : INT_MIN;
        long ls = root->left ? maxSum(root->left) : INT_MIN;
        long rs = root->right ? maxSum(root->right) : INT_MIN;
        
        vector<long> v = {lp, rp, ls, rs, ls + root->val, rs + root->val, ls + rs + root->val, root->val};
        
        return *std::max_element(v.begin(), v.end());
    }
private:
    int maxSum(TreeNode *root) {
        if(!root) return 0;
        return max(maxSum(root->left), maxSum(root->right)) + root->val;
    }
};
