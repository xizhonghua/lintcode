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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        if(A.size()==0) return nullptr;
        return build(A, 0, A.size()-1);
    }
private:
    SegmentTreeNode * build(vector<int>& A, int l, int r) {
        if(l==r) 
            return new SegmentTreeNode(l, l, A[l]);
        
        int mid = (l+r)/2;
        auto node = new SegmentTreeNode(l, r, INT_MIN);
        node->left = build(A, l, mid);
        node->right = build(A, mid+1, r);
        node->max = max(node->left->max, node->right->max);
        return node;
    }
};
