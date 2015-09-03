class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();
        
        int ans = 0;
        for(int i=0;i<rows;++i)
            if(searchRow(matrix, i, target, 0, cols-1)) ++ans;
        for(int i=0;i<cols;++i)
            if(searchCol(matrix, i, target, 0, rows-1)) ++ans;
        return ans/2;
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

