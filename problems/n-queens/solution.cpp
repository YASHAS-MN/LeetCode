class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.'));
        
        // Tracking arrays for fast lookup
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n - 1, false); // Top-left to bottom-right (row - col)
        std::vector<bool> diag2(2 * n - 1, false); // Top-right to bottom-left (row + col)
        
        backtrack(0, n, board, solutions, cols, diag1, diag2);
        return solutions;
    }

private:
    void backtrack(int row, int n, std::vector<std::string>& board, 
                   std::vector<std::vector<std::string>>& solutions,
                   std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        // Base case: All queens are successfully placed
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1; // Offset added to avoid negative indices
            int d2 = row + col;
            
            // Skip if the cell is under attack
            if (cols[col] || diag1[d1] || diag2[d2]) continue;
            
            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            
            // Recurse to place the queen in the next row
            backtrack(row + 1, n, board, solutions, cols, diag1, diag2);
            
            // Backtrack (revert changes)
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};