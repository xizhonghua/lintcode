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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        int h = height(root);
        vector<vector<int>> ans(h, vector<int>());
        inOrder(0, h, ans, root);
        return ans;
    }
private:
    void inOrder(int d, int h, vector<vector<int>>& ans, TreeNode* root) {
        if(!root) return;
        ans[d].push_back(root->val);
        inOrder(d+1, h, ans, root->left);
        inOrder(d+1, h, ans, root->right);
    }
    int height(TreeNode *root) {
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};
