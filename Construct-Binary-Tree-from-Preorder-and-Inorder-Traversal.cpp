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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        int size = preorder.size();
        if (size==0) return nullptr;
        
        TreeNode *node = new TreeNode(preorder.front());
        auto mid_iter = std::find(inorder.begin(), inorder.end(), preorder.front());
        
        auto ls = mid_iter - inorder.begin();
        if(ls>0) {
            auto il = vector<int>(inorder.begin(), mid_iter-1);
            auto pl = vector<int>(preorder.begin()+1, preorder.begin()+ls+1);
            node->left = buildTree(pl, il);    
        }
        
        auto rs = size - ls - 1;
        if(rs>0)
        {
            auto ir = vector<int>(mid_iter+1, inorder.end());
            auto pr = vector<int>(preorder.begin()+ls+1, preorder.end());
            node->right = buildTree(pr, ir);
        }
        return node;
        
    }
};
