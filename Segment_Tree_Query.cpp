/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(!root) return INT_MIN;
        if(start > end) return INT_MIN;
        if(root->start == root->end) return root->max;
        if(root->start == start && root->end == end) return root->max;
        
        int root_mid = (root->start + root->end) / 2;
        if(start <= root_mid && end <= root_mid)
            return query(root->left, start, end);
        if(start > root_mid && end > root_mid)
            return query(root->right, start, end);
        return max(query(root->left, start, root_mid), query(root->right, root_mid+1, end));
    }
};
