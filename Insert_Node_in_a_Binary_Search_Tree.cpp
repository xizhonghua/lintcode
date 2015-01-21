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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(root == nullptr) return node;
        
        auto p = root;
        
        while(true)
        {
            if(node->val < p->val)
            {
                if(p->left != nullptr)
                    p = p->left;
                else
                {
                    p->left = node;
                    break;
                }
            }
            else {
                if(p->right != nullptr)
                    p = p->right;
                else
                {
                    p->right = node;
                    break;
                }
            }
        }
        
        
        return root;
    }
};
