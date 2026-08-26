class Solution {
public:

    bool valid(vector<vector<char>>& board, int row, int col, char num)
    {
        int i,j;
        for(i=0; i<9; i++)
            if(board[row][i] == num) return false;

        for(j=0; j<9; j++)
            if(board[j][col] == num) return false;

        int rowB = (row/3)*3;
        int colB = (col/3)*3;

        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
                if(board[rowB+i][colB+j] == num) return false;
        
        return true;
    }

    bool sol(vector<vector<char>>& board, int pos)
    {
        int row = pos/9;
        int col = pos%9;

        if(pos == 81) return true;

        if(board[row][col] != '.' ) return sol(board, pos+1);

        for(char num='1'; num<='9'; num++)
        {
            if(valid(board, row, col, num)) 
                {
                    board[row][col] = num;

                    if(sol(board, pos+1)) return true;

                    board[row][col] = '.';
                }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sol(board, 0);
    }
};