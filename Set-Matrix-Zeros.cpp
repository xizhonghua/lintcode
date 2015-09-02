class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        int h = matrix.size();
        if(h==0) return;
        int w = matrix[0].size();
        
        set<int> cols;
        set<int> rows;
        
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j)
                if(matrix[i][j]==0) {
                    cols.insert(j);
                    rows.insert(i);
                }
        
        for(auto c : cols)
            for(int i=0;i<h;++i)
                matrix[i][c] = 0;
                
        for(auto r : rows)
            for(int j=0;j<w;++j)
                matrix[r][j] = 0;
    }
};
