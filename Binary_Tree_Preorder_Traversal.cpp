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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> v;
        
        if(root == nullptr) return v;
        
        stack<pair<TreeNode*,int>> m;
        
        m.push(make_pair(root,0));
        
        while(!m.empty())
        {
            auto& p = m.top();
            
            switch(p.second++)
            {
                // not visited
                case 0:
                    v.push_back(p.first->val);
                    break;
                // visited itself
                case 1: 
                    if(p.first->left) 
                        m.push(make_pair(p.first->left,0));
                    break;
                // visited left child
                case 2:
                    if(p.first->right)
                        m.push(make_pair(p.first->right, 0));
                    break;
                // visited right child
                case 3:
                    m.pop();
                    break;
            }
        }
        
        return v;
    }
};

