class Solution {
public:
    int rows;
    int cols;

    bool sol(vector<vector<char>>& board, string& word, int row, int col, int ind){
            if(ind == word.length()-1)
             return true;

             char org = board[row][col];
             board[row][col] = '#';

             if(row-1>=0 && board[row-1][col]==word[ind+1]){
                if(sol(board, word, row-1, col, ind+1))
                return true;
             }

             if(row+1<rows && board[row+1][col]==word[ind+1]){
                if(sol(board, word, row+1, col, ind+1))
                return true;
             }

             if(col-1>=0 && board[row][col-1]==word[ind+1]){
                if(sol(board, word, row, col-1, ind+1))
                return true;
             }

             if(col+1<cols && board[row][col+1]==word[ind+1]){
                if(sol(board, word, row, col+1, ind+1))
                return true;
             }

             board[row][col]=org;

             return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(board[row][col] == word[0])
                   if(sol(board, word, row, col, 0))
                        return true;
            }
        }
        return false;
    }
};