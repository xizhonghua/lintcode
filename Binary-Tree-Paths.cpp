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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        
        vector<string> ans;
        string cur = std::to_string(root->val);
        if(root->left || root->right) {
            binaryTreePaths(root->left, ans, cur);
            binaryTreePaths(root->right, ans, cur);
            return ans;
        }
        return {cur};
    }
private:
    void binaryTreePaths(TreeNode* root, vector<string>& ans, string cur) {
        if(!root) return;
        cur += "->" + std::to_string(root->val);
        if(!root->left && !root->right) {
            ans.push_back(cur);
            return;
        }
        binaryTreePaths(root->left, ans, cur);
        binaryTreePaths(root->right, ans, cur);
    }
};
