class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        auto cols = vector<vector<int>>(9, vector<int>(9,0));
        auto rows = cols;
        auto blocks = cols;
        
        
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j) {
                char s = board[i][j];
                if(s == '.') continue;
                int n = s - '0';
                int bi = (i/3)*3 + j/3;
                
                if(cols[j][n] || rows[i][n] || blocks[bi][n]) return false;
                
                cols[j][n] = rows[i][n] = blocks[bi][n] = 1;
            }
        
        return true;
    }
};
