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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(root == nullptr) return nullptr;
        
        map<int,TreeNode*> ma, mb;
        
        ma[0] = root;
        mb[0] = root;
        auto r1 = findParents(0, root, A, ma);
        auto r2 = findParents(0, root, B, mb);
        
        auto ita = ma.crbegin();
        auto itb = mb.crbegin();
        
        while(ita->second != itb->second)
        {
            if(ita->first > itb->first)
                ita++;
            else
                itb++;
        }
        
        return ita->second;
        
    }
private:
    bool findParents(int depth, TreeNode *root, TreeNode *t, map<int,TreeNode*> &m)
    {
        if(root == nullptr) return false;
        if(root == t) {
            return true;
        }
        if(findParents(depth+1, root->left, t, m)) {
            m[depth+1] = root->left;
            return true;
        }
        if(findParents(depth+1, root->right, t, m)) {
            m[depth+1] = root->right;
            return true;
        }
        
        return false;
    }
    
};
