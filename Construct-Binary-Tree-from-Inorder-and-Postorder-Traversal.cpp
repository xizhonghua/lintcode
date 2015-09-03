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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = postorder.size();
        if (size==0) return nullptr;
        
        TreeNode *node = new TreeNode(postorder.back());
        auto mid_iter = std::find(inorder.begin(), inorder.end(), postorder.back());
        
        auto ls = mid_iter - inorder.begin();
        if(ls>0) {
            auto il = vector<int>(inorder.begin(), mid_iter-1);
            auto pl = vector<int>(postorder.begin(), postorder.begin()+ls);
            node->left = buildTree(il, pl);    
        }
        
        auto rs = size - ls - 1;
        if(rs>0)
        {
            auto ir = vector<int>(mid_iter+1, inorder.end());
            auto pr = vector<int>(postorder.begin()+ls, postorder.end()-1);
            node->right = buildTree(ir, pr);
        }
        return node;
    }
};
