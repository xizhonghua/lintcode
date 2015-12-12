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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        if(!root) return;
        f(root);
    }
private:
    TreeNode* f(TreeNode *root) {
        if(!root) return nullptr;
        auto l = root->left;
        auto r = root->right;
        auto tail_l = f(l);
        auto tail_r = f(r);
        if(l) {
            tail_l->left = nullptr;
            tail_l->right = r;
            root->right = l;
            root->left = nullptr;
            return tail_r ? tail_r : tail_l;
        } else if(r) {
            return tail_r;
        }
        return root;
    }
};
