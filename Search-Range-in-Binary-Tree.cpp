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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> ans;
        if(!root) return ans;
        if(k2<k1) return ans;
        if(root->val >= k1 && root->val <= k2)
            ans.push_back(root->val);
        auto l = searchRange(root->left, k1, min(k2, root->val));
        auto r = searchRange(root->right, max(k1, root->val), k2);
        l.insert(l.end(), ans.begin(), ans.end());
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};
