/*
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return sortedArrayToBST(A, 0, A.size()-1);
    }
private:
    TreeNode *sortedArrayToBST(vector<int> &A, int l, int r) {
        if(l>r) return nullptr;
        int m = (l+r)>>1;
        TreeNode *node = new TreeNode(A[m]);
        node->left = sortedArrayToBST(A, l, m-1);
        node->right = sortedArrayToBST(A, m+1, r);
        return node;
    }
};
