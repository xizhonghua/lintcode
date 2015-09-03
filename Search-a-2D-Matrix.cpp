class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();
        
        for(int i=0;i<rows;++i)
            if(searchRow(matrix, i, target, 0, cols-1)) return true;
        for(int i=0;i<cols;++i)
            if(searchCol(matrix, i, target, 0, rows-1)) return true;
        
        return false;
    }
private:
    bool searchRow(const vector<vector<int>> &m, int row, int target, int l, int r) {
        if(l>r) return false;
        if(l==r) return m[row][l] == target;
        int mid = (l+r)>>1;
        int p = m[row][mid];
        if(p==target) return true;
        return p > target ? searchRow(m,row,target,l,mid-1) : searchRow(m,row,target,mid+1,r);
    }
    
    bool searchCol(const vector<vector<int>> &m, int col, int target, int l, int r) {
        if(l>r) return false;
        if(l==r) return m[l][col] == target;
        int mid = (l+r)>>1;
        int p = m[mid][col];
        if(p==target) return true;
        return p > target ? searchCol(m,col,target,l,mid-1) : searchCol(m,col,target,mid+1,r);
    }
};

