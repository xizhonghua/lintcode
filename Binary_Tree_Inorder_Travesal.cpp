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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
                    if(p.first->left) 
                        m.push(make_pair(p.first->left,0));
                    break;
                // visited left child
                case 1:
                    v.push_back(p.first->val);
                    break;
                // visited itself
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
