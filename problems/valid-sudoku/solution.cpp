class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row, col;

        for(row=0; row<9; row++)
        {
            for(col=0; col<9; col++)
            {
                if(board[row][col] == '.') continue;

                char num = board[row][col];

                for(int i=0; i<9; i++)
                    if(i != col && board[row][i] == num) return false;

                for(int j=0; j<9; j++)
                    if(j != row && board[j][col] == num) return false;

                int rowB = (row/3)*3;
                int colB = (col/3)*3;

                for(int i=0; i<3; i++)
                    for(int j=0; j<3; j++)
                        if((rowB+i != row || colB+j != col) &&board[rowB+i][colB+j] == num) return false;
            }
        }
        return true;
    }
};